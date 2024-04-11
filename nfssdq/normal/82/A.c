
#include<stdio.h>
#include<math.h>
main()
{
long int a,b,c,d,e,f,g,x,y,z;
double m;
scanf("%ld",&a);
b=1;
c=b*5;
while(c<a)
{
b*=2;
c+=b*5;
}
c-=b*5;
d=a-c;
m=(double)d/b;
if(m<=1)
{
printf("Sheldon");
}
else if(m<=2)
{
printf("Leonard");
}
else if(m<=3)
{
printf("Penny");
}
else if(m<=4)
{
printf("Rajesh");
}
else
{
printf("Howard");
}
return 0;
}