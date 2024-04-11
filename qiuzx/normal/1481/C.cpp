#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m,a[N],b[N],c[N],id[N],col[N];
vector<ll> nc[N];
bool check()
{
	ll i;
	for(i=0;i<m;i++)
	{
		a[col[i]]=c[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
int main(){
	ll t,lps,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			nc[i].clear();
			id[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			b[i]--;
			if(a[i]!=b[i])
			{
				nc[b[i]].push_back(i);
			}
		}
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			{
				nc[b[i]].push_back(i);
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&c[i]);
			c[i]--;
		}
		lps=-1;
		for(i=m-1;i>=0;i--)
		{
			if(id[c[i]]<nc[c[i]].size())
			{
				col[i]=nc[c[i]][id[c[i]]];
				id[c[i]]++;
				lps=col[i];
				continue;
			}
			if(lps==-1)
			{
				i=LINF;
				break;
			}
			col[i]=lps;
		}
		if(i==LINF||(!check()))
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(i=0;i<m;i++)
			{
				printf("%lld ",col[i]+1);
			}
			puts("");
		}
	}
	return 0;
}