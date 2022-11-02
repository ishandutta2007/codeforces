#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n,x;
		scanf("%d%d",&n,&x);
		int del=0,maxd=0;
		rep(i,n)
		{
			int d,h;
			scanf("%d%d",&d,&h);
			del=max(del,d-h);
			maxd=max(maxd,d);
		}
		if(x<=maxd)puts("1");
		else if(del==0)puts("-1");
		else printf("%d\n",(x-maxd-1)/del+2);
	}
	return 0;
}