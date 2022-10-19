// LUOGU_RID: 90567957
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 7010
using namespace std;
ll n,s[2][N],st[2][N],sz[2],deg[2][N];
int main(){
	ll i,j;
	scanf("%d%d",&n,&sz[0]);
	for(i=0;i<sz[0];i++)
	{
		scanf("%d",&s[0][i]);
	}
	scanf("%d",&sz[1]);
	for(i=0;i<sz[1];i++)
	{
		scanf("%d",&s[1][i]);
	}
	queue<pair<ll,ll> > q;
	memset(st,-1,sizeof(st));
	st[0][0]=st[1][0]=0;
	q.push(make_pair(0,0));
	q.push(make_pair(1,0));
	while(!q.empty())
	{
		ll x=q.front().S,y=q.front().F;
		q.pop();
		for(i=0;i<sz[y^1];i++)
		{
			j=(x+n-s[y^1][i])%n;
			if(st[y^1][j]!=-1)
			{
				continue;
			}
			if(st[y][x]==0)
			{
				st[y^1][j]=1;
				q.push(make_pair(y^1,j));
				continue;
			}
			deg[y^1][j]++;
			if(deg[y^1][j]==sz[y^1])
			{
				st[y^1][j]=0;
				q.push(make_pair(y^1,j));
			}
		}
	}
	for(i=1;i<n;i++)
	{
		if(st[0][i]==0)
		{
			printf("Lose ");
		}
		else if(st[0][i]==1)
		{
			printf("Win ");
		}
		else
		{
			printf("Loop ");
		}
	}
	puts("");
	for(i=1;i<n;i++)
	{
		if(st[1][i]==0)
		{
			printf("Lose ");
		}
		else if(st[1][i]==1)
		{
			printf("Win ");
		}
		else
		{
			printf("Loop ");
		}
	}
	puts("");
	return 0;
}