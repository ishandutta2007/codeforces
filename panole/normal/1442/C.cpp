#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const long long inf=1000000000ll;

long long dis[200010][21];
int n,m,x,y;
vector<int> v[2][200010];
set<pair<long long,pair<int,int>> > s;

void upd(int x,int y,long long v)
{
	s.erase(make_pair(dis[x][y],make_pair(x,y)));
	dis[x][y]=v;
	s.insert(make_pair(dis[x][y],make_pair(x,y)));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		v[0][x].push_back(y),v[1][y].push_back(x);
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<=20; j++) dis[i][j]=10000000;
	dis[1][0]=0,s.insert(make_pair(0,make_pair(1,0)));
	while (!s.empty())
	{
		x=(*s.begin()).second.first,y=(*s.begin()).second.second,s.erase(s.begin());
		if (y<20&&dis[x][y+1]>dis[x][y]+(1<<y)) upd(x,y+1,dis[x][y]+(1<<y));
		for (int t,i=0,sz=v[y&1][x].size(); i<sz; i++)
			if (dis[t=v[y&1][x][i]][y]>dis[x][y]+1) upd(t,y,dis[x][y]+1);
	}
	long long ans=10000000;
	for (int i=0; i<=20; i++) ans=min(ans,dis[n][i]);
	if (ans<10000000) return printf("%d\n",ans),0;
	for (int i=1; i<=n; i++) dis[i][0]=dis[i][1]=inf*inf;
	s.clear(),dis[1][0]=0,s.insert(make_pair(0,make_pair(1,0)));
	while (!s.empty())
	{
		x=(*s.begin()).second.first,y=(*s.begin()).second.second,s.erase(s.begin());
		if (dis[x][y^1]>dis[x][y]+inf) upd(x,y^1,dis[x][y]+inf);
		for (int t,i=0,sz=v[y][x].size(); i<sz; i++)
			if (dis[t=v[y][x][i]][y]>dis[x][y]+1) 
				upd(t,y,dis[x][y]+1);
	}
	ans=min(dis[n][0],dis[n][1]);
	int mi=1;
	for (int i=1; i<=ans/inf; i++) mi=2ll*mi%mod;
	printf("%lld\n",(ans%inf+mi-1+mod)%mod);
	return 0;
}