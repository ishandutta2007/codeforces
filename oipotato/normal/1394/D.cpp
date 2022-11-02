#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const long long inf=1000000000ll*1000;
const int N=200010;
vector<int>g[N];
vector<pair<long long,long long>>G;
long long f[N][2];
int t[N],h[N],n,rt;
bool cmp(pair<long long,long long>x,pair<long long,long long>y){return x.second-x.first<y.second-y.first;}
void update(long long&f0,long long&f1,int c0,int c1,long long tans,int t)
{
	if(c0>c1)
	{
		f0=min(f0,tans+1ll*t*(c0-1));
		f1=min(f1,tans+1ll*t*c0);
	}
	else if(c0<c1)
	{
		f0=min(f0,tans+1ll*t*c1);
		f1=min(f1,tans+1ll*t*(c1-1));
	}
	else
	{
		f0=min(f0,tans+1ll*t*c1);
		f1=min(f1,tans+1ll*t*c0);
	}
}
void dfs(int p,int fa)
{
	for(auto i:g[p])if(i!=fa)dfs(i,p);
	G.clear();
	for(auto i:g[p])if(i!=fa)G.pb(mp(f[i][0],f[i][1]));
	if(p==rt)
	{
		printf("%lld\n",min(G[0].first,G[0].second)+t[p]);
		return;
	}
	sort(G.begin(),G.end(),cmp);
	int cnt=0;long long sum=0;
	for(auto i:G)sum+=i.first,cnt++;
	long long ans0=inf,ans1=inf;
	update(ans0,ans1,cnt,0,sum,t[p]);
	int now=0;
	for(auto i:G)
	{
		now++;
		sum+=i.second-i.first;
		update(ans0,ans1,cnt-now,now,sum,t[p]);
	}
	f[p][0]=f[p][1]=inf;
	if(h[p]<=h[fa])f[p][0]=ans0+t[p];
	if(h[p]>=h[fa])f[p][1]=ans1+t[p];
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&t[i]);
	rep(i,n)scanf("%d",&h[i]);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
	rep(i,n)if(g[i].size()==1){rt=i;break;}
	dfs(rt,0);
	return 0;
}