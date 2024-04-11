#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
const int mod=1000000007;
int n,m,k,l,r,t;
int power(LL x,int y)
{
	LL res=1;
	while(y!=0)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	l=n+1;
	r=0;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==y-1)continue;
		if(y-x!=k+1)
		{
			puts("0");
			return 0;
		}
		t++;
		l=min(l,x);
		r=max(r,y);
	}
	if(r-l>=2*k+2)
	{
		puts("0");
		return 0;
	}
	LL ans=0;
	if(t!=0)for(int i=max(1,r-k-k-1);i<=l;i++)
	{
		int left=i,right=min(n-k-1,i+k);
		if(i==l)t--;
		ans+=power(2,right-left-t);
	}
	else
	{
		for(int i=1;i<=n-k-1;i++)
		{
			int left=i+1,right=min(n-k-1,i+k);
			ans+=power(2,right-left+1);
		}
		ans++;
	}
	printf("%I64d\n",ans%mod);
	return 0;
}
/*
7 1 3
1 5
*/