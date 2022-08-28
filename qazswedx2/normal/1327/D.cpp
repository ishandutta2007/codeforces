#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,p[500005],c[500005],a[500005],vis[500005],at;
int solve(int x)
{
	for(int i=0;i<x;i++)
	{
		int fl=1,val=c[a[i]];
		for(int j=i;j<at;j+=x)
			if(val!=c[a[j]])
			{
				fl=0;
				break;
			}
		if(fl) return x;
	}
	return 1e9;
}
int getans()
{
	int ans=1e9;
	for(int i=1;1ll*i*i<=at;i++)
		if(at%i==0)
			ans=min(ans,min(solve(i),solve(at/i)));
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		int nans=1e9;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				at=0;
				int nw=i;
				while(!vis[nw])
				{
					vis[nw]=1;
					a[at++]=nw;
					nw=p[nw];
				}
				nans=min(nans,getans());
			}
		printf("%d\n",nans);
	}
	return 0;
}