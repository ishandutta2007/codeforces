#include<cstdio>
#include<cstring>
#include<algorithm>
int a,b,x,y,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b)) printf("-1\n");
		else printf("%d\n",(y-x)/(a+b));
	}
	return 0;
}