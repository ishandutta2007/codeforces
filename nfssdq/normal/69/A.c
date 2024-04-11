#include<stdio.h>
main()
{
int a[4];
int b,c,d,e,f,x,y,z;
scanf("%d",&b);
for(x=1;x<=3;x=x+1)
{
a[x]=0;
}
for(x=1;x<=b;x=x+1)
{
for(y=1;y<=3;y=y+1)
{
scanf("%d",&c);
a[y]+=c;
}
}
for(x=1;x<=3;x=x+1)
{
if(a[x]!=0)
{
printf("NO\n");
return 0;
}
}
printf("YES\n");
return 0;
}