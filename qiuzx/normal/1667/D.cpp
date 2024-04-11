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
#define N 200010
using namespace std;
vector<ll> vt[N];
ll f[N],n;
void dfs(ll x,ll lst)
{
	ll i;
	f[x]=(vt[x].size()+1)/2;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
			f[x]-=f[vt[x][i]];
		}
	}
	return;
}
void print(ll x,ll lst)
{
	ll i;
	vector<ll> nd1,nd2;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			if(f[vt[x][i]])
			{
				nd1.push_back(vt[x][i]);
			}
			else
			{
				nd2.push_back(vt[x][i]);
			}
		}
		else
		{
			if(f[x])
			{
				nd1.push_back(x);
			}
			else
			{
				nd2.push_back(x);
			}
		}
	}
	if(nd1.size()==nd2.size())
	{
		for(i=0;i<nd2.size();i++)
		{
			if(nd2[i]!=x)
			{
				print(nd2[i],x);
			}
			else
			{
				printf("%lld %lld\n",x+1,lst+1);
			}
			if(nd1[i]!=x)
			{
				print(nd1[i],x);
			}
			else
			{
				printf("%lld %lld\n",x+1,lst+1);
			}
		}
	}
	else
	{
		for(i=0;i<nd1.size();i++)
		{
			if(nd1[i]!=x)
			{
				print(nd1[i],x);
			}
			else
			{
				printf("%lld %lld\n",x+1,lst+1);
			}
			if(nd2.size()>i)
			{
				if(nd2[i]!=x)
				{
					print(nd2[i],x);
				}
				else
				{
					printf("%lld %lld\n",x+1,lst+1);
				}
			}
		}
	}
	return;
}
int main(){
	ll T,i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&x,&y);
			x--,y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		dfs(0,-1);
		for(i=0;i<n;i++)
		{
			if(f[i]!=0&&f[i]!=1)
			{
				i=-1;
				break;
			}
		}
		if(i==-1||f[0]!=0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		print(0,-1);
	}
	return 0;
}