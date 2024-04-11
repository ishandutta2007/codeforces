#include<cstdio>
#include<cstring>
#include<cstdlib>

int x1,x2,x3,max1,max2,maxx;

int abs(int x) {return x<0?-x:x;}

int main()
{
	scanf("%d%d%d",&x1,&x2,&x3);
	maxx=1; max1=x1; 
	if (x2>max1) max1=x2,maxx=2;
	if (x3>max1) max1=x3,maxx=3;
	if (maxx!=1) max2=x1; else max2=x2;
	if (x2>max2&&maxx!=2) max2=x2;
	if (x3>max2&&maxx!=3) max2=x3;
	printf("%d",abs(x1-max2)+abs(x2-max2)+abs(x3-max2));
	return 0;
}