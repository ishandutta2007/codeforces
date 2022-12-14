#include<stdio.h>
main()
{
int x,y,z,b=0,d,e,f,g,h,i,j;
y=0;
int a[100][100],m[100];
scanf("%d %d",&b,&d);
for(x=0;x<b;x++)
{
for(y=0;y<b;y++)
{
a[x][y]=0;
}
m[x]=0;
}
for(x=0;x<d;x++)
{
   scanf("%d %d",&e,&f);
   a[e-1][f-1]=1;
   a[f-1][e-1]=1;
}
j=0;
i=0;
m:h=0;
for(x=0;x<b;x++)
{
   i=0;
   for(y=0;y<b;y++)
   {
      if(a[x][y]==1)
      {
         i++;
      }
   }
   m[x]=i;
}
for(x=0;x<b;x++)
{
    if(m[x]==1)
   {
      h++;
      for(y=0;y<b;y++)
      {
         a[x][y]=0;
         a[y][x]=0;
      }
   }
}
if(h>0)
{
j++;
goto m;
}

printf("%d\n",j);
return 0;
}