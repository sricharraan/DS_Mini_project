#include<stdio.h>
#include<conio.h>
#include<time.h>
time_t rawtime;
struct tm*info;


struct space
 {int num;int hr;int min;int sec;};
struct space a[3][3]={0};


void DISP()
{
int j,k;

for(j=0;j<3;j++)
	 {for(k=0;k<3;k++)
	    { printf("%d ",a[j][k].num);

	      }
	  printf("\n");
	  }

}

void IN()
{int flag=0;
 int j,k,number;


//check empty space
 for(j=0;j<3;j++)
     {for(k=0;k<3;k++)
	 {if(a[j][k].num==0)
	    {flag=1;
	    printf("enter car number");
	    scanf("%d",&number);
	    a[j][k].num=number;

	     //get time
	    time(&rawtime);
	    info=gmtime(&rawtime);

	    //assign time
	    a[j][k].hr=info->tm_hour+8;
	    a[j][k].min=info->tm_min;
	    a[j][k].sec=info->tm_sec;
	    printf("your alloted space is %d%d",j,k);
	    if(flag==1)
		{break;}
	    }
	 }
     if(flag==1)
       {break;}
     }
if(flag==0)
 {printf("No space left");}

}

void OUT()
{int j,k,s,flag=0,hour,min,sec,totaltime;
printf("enter car no");
scanf("%d",&s);

//check car in array
for(j=0;j<3;j++)
     {for(k=0;k<3;k++)
	 {if(a[j][k].num==s)
	    {flag=1;
	    break;}
	 }
     if(flag==1)
       {break;}
     }
if(flag==0)
  {printf("no such car");}
if(flag==1)
  {
    //get time
    time(&rawtime);
   info=gmtime(&rawtime);
    
    //calculate cost using time
    hour=(info->tm_hour+8)-a[j][k].hr;
    min=(info->tm_min)-a[j][k].min;
    sec=(info->tm_sec)-a[j][k].sec;
    totaltime=(hour*3600)+(min*60)+sec;

  printf("time in sec %d\n",totaltime);
  printf("cost is %d",(totaltime/10));
  a[j][k].hr=0;
  a[j][k].min=0;
  a[j][k].num=0;
  }


}


void main()
{int i=0;
int j,k;

//assign array of 0
for(j=0;j<3;j++)
	 {for(k=0;k<3;k++)
        	{a[j][k].num=0;a[j][k].hr=0;a[j][k].min=0;a[j][k].sec=0;}

         }
clrscr();


while (i!=4)
{     printf("WELCOME TO PARKING LOT");
      printf("\n1.IN 2.OUT 3.DISPLAY 4.EXIT\n");
      for(j=0;j<3;j++)
	 {for(k=0;k<3;k++)
	     {if(a[j][k].num!=0)
		{textcolor(RED);
		 cprintf("0 ");}
	     else{textcolor(BLUE+BLINK);
		     cprintf("0 ");}
	      }
	  printf("\n");
	  }
      i=0;
      scanf("%d",&i);

      if(i==1)
	 {IN();
	 getch();
	 clrscr();
	 }
      if(i==2)
	 {OUT();
	 getch();
	 clrscr();
	 }
      if(i==3)
	{DISP();
	getch();
	clrscr();
	 }
      }

getch();
}
