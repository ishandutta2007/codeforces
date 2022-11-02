#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
const int N=100010;
int f[N][2],n,k;
vector<pair<int,int>>g[N];
vector<int>G;
void dfs(int p,int fa)
{
	for(auto i:g[p])if(i.first!=fa)dfs(i.first,p);
	G.clear();
	for(auto i:g[p])if(i.first!=fa)G.pb(f[i.first][1]+i.second);
	sort(G.begin(),G.end(),greater<int>());
	int sum=0,nxt=0,cnt=G.size();
	rep(i,min(cnt,k-1))sum+=G[i-1];
	if(cnt>=k)nxt=G[k-1];
	f[p][1]=sum;
	f[p][0]=sum;
	for(auto i:g[p])if(i.first!=fa)f[p][0]=max(f[p][0],f[i.first][0]+i.second+sum-max(0,f[i.first][1]+i.second-nxt));
}
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,n-1){int x,y,z;scanf("%d%d%d",&x,&y,&z);x++;y++;g[x].pb(mp(y,z));g[y].pb(mp(x,z));}
	dfs(1,0);
	printf("%d\n",max(f[1][0],f[1][1]));
	return 0;
}