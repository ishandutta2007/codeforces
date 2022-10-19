//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],f[N],lstf[N],g[N],lstg[N];
void print(ll x,ll tp)
{
	if(x==0)
	{
		printf("%lld ",tp);
		return;
	}
	if(tp==0)
	{
		print(x-1,lstf[x]);
		printf("0 ");
		return;
	}
	print(x-1,lstg[x]);
	printf("1 ");
	return;
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	memset(f,-63,sizeof(f));
	memset(g,63,sizeof(g));
	memset(lstf,-1,sizeof(lstf));
	memset(lstg,-1,sizeof(lstg));
	lstf[0]=0;
	lstg[0]=1;
	f[0]=INF;
	g[0]=-INF;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			if(f[i]<f[i-1]&&lstf[i-1]!=-1)
			{
				f[i]=f[i-1];
				lstf[i]=0;
			}
		}
		else if(a[i]<a[i-1])
		{
			if(g[i]>g[i-1]&&lstg[i-1]!=-1)
			{
				g[i]=g[i-1];
				lstg[i]=1;
			}
		}
		if(lstf[i-1]!=-1&&a[i]<f[i-1])
		{
			if(g[i]>a[i-1])
			{
				g[i]=a[i-1];
				lstg[i]=0;
			}
		}
		if(lstg[i-1]!=-1&&a[i]>g[i-1])
		{
			if(f[i]<a[i-1])
			{
				f[i]=a[i-1];
				lstf[i]=1;
			}
		}
	}
	if(lstf[n-1]!=-1)
	{
		puts("YES");
		print(n-1,0);
		return 0;
	}
	if(lstg[n-1]!=-1)
	{
		puts("YES");
		print(n-1,1);
		return 0;
	}
	puts("NO");
	return 0;
}