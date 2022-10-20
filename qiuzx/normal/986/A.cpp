#include <bits/stdc++.h>
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define ll long long
#define N 100010
#define M 110
using namespace std;
ll n,m,k,s,dist[N][M],fs;
bool vis[N][M];
queue<pair<ll,ll> > q[M];
vector<ll> vt[N],ans;
int main(){
	ll i,j,a,st,x,y;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
	memset(dist,-1,sizeof(dist));
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
		a--;
		q[a].push(make_pair(i,0));
		vis[i][a]=true;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(i=0;i<k;i++)
	{
		while(q[i].size())
		{
			a=q[i].front().F;
			st=q[i].front().S;
			q[i].pop();
			dist[a][i]=st;
			for(j=0;j<vt[a].size();j++)
			{
				x=vt[a][j];
				if(!vis[x][i])
				{
					vis[x][i]=true;
					q[i].push(make_pair(x,st+1));
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ans.clear();
		fs=0;
		for(j=0;j<k;j++)
		{
			if(dist[i][j]!=-1)
			{
				ans.push_back(dist[i][j]);
			}
		}
		sort(ans.begin(),ans.end());
		for(j=0;j<s;j++)
		{
			fs+=ans[j];
		}
		printf("%lld ",fs);
	}
	puts("");
	return 0;
}