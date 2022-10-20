//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
#define B 350
using namespace std;
int n,m,q,bid[N],rel[N][B];
ll ans[N],a[N],tg[N];
vector<int> v[N],bigid,app[N];
int main(){
	int i,j,k,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		bid[i]=-1;
		scanf("%d",&x);
		if(x>B)
		{
			bid[i]=bigid.size();
			bigid.push_back(i);
		}
		v[i].resize(x);
		for(j=0;j<x;j++)
		{
			scanf("%d",&v[i][j]);
			v[i][j]--;
			ans[i]+=a[v[i][j]];
			if(x>B)
			{
				app[v[i][j]].push_back(bid[i]);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			for(k=0;k<app[v[i][j]].size();k++)
			{
				rel[i][app[v[i][j]][k]]++;
			}
		}
	}
	while(q--)
	{
		char cc;
		scanf(" %c",&cc);
		if(cc=='+')
		{
			scanf("%d%d",&x,&y);
			x--;
			if(bid[x]==-1)
			{
				for(j=0;j<v[x].size();j++)
				{
					a[v[x][j]]+=y;
				}
				for(j=0;j<bigid.size();j++)
				{
					ans[bigid[j]]+=rel[x][j]*y;
				}
			}
			else
			{
				tg[x]+=y;
			}
		}
		else
		{
			scanf("%d",&x);
			x--;
			ll res=0;
			if(bid[x]==-1)
			{
				for(j=0;j<v[x].size();j++)
				{
					res+=a[v[x][j]];
				}
			}
			else
			{
				res=ans[x];
			}
			for(j=0;j<bigid.size();j++)
			{
				res+=tg[bigid[j]]*rel[x][j];
			}
			printf("%I64d\n",res);
		}
	}
	return 0;
}