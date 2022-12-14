#include<stdio.h>
main()
{
int x,y,z,b=0;
y=0;
int a[200];
scanf("%d",&z);
for(x=0;x<z;x++)
{
   scanf("%d",&a[x]);
   y+=a[x];
}
for(x=0;x<z;x++)
{
   if((y-a[x])%2==0)
   {
      b++;
   }
}
printf("%d\n",b);
return 0;
}