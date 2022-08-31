#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int l,r,x,nw=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l,&r,&x);
			nw|=x;
		}
		int nww=n-1,c=nw%mod;
		for(int i=1;i<=nww;i++)
			c=2*c%mod;
		printf("%d\n",c);
	}
}