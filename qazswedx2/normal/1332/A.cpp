#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,d,x,y,lx,ly,rx,ry,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d%d%d%d%d%d",&x,&y,&lx,&ly,&rx,&ry);
		int flx=1,fly=1;
		if(lx==rx)
		{
			flx=(a==0&&b==0);
		}
		else
		{
			if(x-a+b<lx||x-a+b>rx) flx=0;
		}
		if(ly==ry)
		{
			fly=(c==0&&d==0);
		}
		else
		{
			if(y-c+d<ly||y-c+d>ry) fly=0;
		}
		if(flx&&fly) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}