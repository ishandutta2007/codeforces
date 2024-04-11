#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=5e8+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
pair<pair<int,int>,pair<int,int>>ans;
vector<int>e[N],a;
pair<int,int>len[N][3];
pair<int,pair<int,int>>dp[N][3];
int deg[N];
bool can[N];
void dfs(int now,int father)
{
	can[now]=deg[now]<3;
	for (int to:e[now]) if (to!=father) dfs(to,now),can[now]&=can[to];
}
pair<int,int>dfs0(int now,int father)
{
	len[now][0].first=len[now][1].first=-inf;
	if (can[now]) len[now][0]=make_pair(0,now);
	for (int to:e[now])
	{
		if (to==father) continue;
		len[now][2]=dfs0(to,now);
		len[now][2].first++;
		sort(len[now],len[now]+3,greater<pair<int,int>>());
	}
	if (can[now]) return len[now][0];
	return make_pair(-inf,0);
}
pair<int,pair<int,int>>dfs1(int now,int father)
{
	dp[now][0].first=dp[now][1].first=-inf;
	if (deg[now]>=3) dp[now][0]=make_pair(0,make_pair(len[now][0].first+len[now][1].first,now));
	for (int to:e[now])
	{
		if (to==father) continue;
		dp[now][2]=dfs1(to,now);
		dp[now][2].first++;
		sort(dp[now],dp[now]+3,greater<pair<int,pair<int,int>>>());
	}
	ans=max(ans,make_pair(make_pair(dp[now][0].first+dp[now][1].first,dp[now][0].second.first+dp[now][1].second.first),
						  make_pair(dp[now][0].second.second,dp[now][1].second.second)));
	if (deg[now]>=3)
	ans=max(ans,make_pair(make_pair(dp[now][0].first,dp[now][0].second.first+len[now][0].first+len[now][1].first),
						  make_pair(dp[now][0].second.second,now)));
	return dp[now][0];
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	for (int i=1;i<=n;i++) if (deg[i]>=3) a.push_back(i);
	if (a.empty())
	{
		vector<int>tmp;
		for (int i=1;i<=n;i++) if (deg[i]==1) tmp.push_back(i);
		print(tmp[0],' '),print(tmp[0]);
		print(tmp[1],' '),print(e[tmp[0]][0]);
	}
	int rt=a[0];
	dfs(rt,0);
	dfs0(rt,0);
	if ((int)a.size()==1)
	{
		if (deg[rt]==3)
		{	
			print(len[e[rt][0]][0].second,' '),print(len[e[rt][1]][0].second);
			print(len[e[rt][2]][0].second,' '),print(e[rt][2]);
		}
		pair<int,int>tmp[5];
		for (int to:e[rt])
		{
			tmp[4]=len[to][0];
			sort(tmp,tmp+5,greater<pair<int,int>>());
		}
		print(tmp[0].second,' '),print(tmp[1].second);
		print(tmp[2].second,' '),print(tmp[3].second);
		return 0;
	}
	dfs1(rt,0);
	print(len[ans.second.first][0].second,' '),print(len[ans.second.second][0].second);
	print(len[ans.second.first][1].second,' '),print(len[ans.second.second][1].second);
	
	return 0;
}
/*
8
1 2
1 3
1 4
2 5
5 6
6 7
6 8
*/