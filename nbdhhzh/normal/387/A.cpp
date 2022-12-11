#include<cstdio>
using namespace std;
int x1,y1,x2,y2,x3,y3;
int main()
{
	scanf("%d:%d",&x1,&y1);
	scanf("%d:%d",&x2,&y2);
	y3=y1-y2;x3=x1-x2;
	if (y3<0)y3+=60,x3-=1;
	if (x3<0)x3+=24;
	if (x3<10)printf("0");printf("%d:",x3);
	if (y3<10)printf("0");printf("%d",y3);
}