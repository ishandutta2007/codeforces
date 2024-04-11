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
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int N=500010;
int len[N][2],d[N],n,m;
queue<int>q;
vector<pair<int,int>>g[N];
char ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,m){int x,y,t;scanf("%d%d%d",&x,&y,&t);g[y].pb(mp(x,t));}
	rep(i,n)ans[i]='0';
	q.push(n);
	for(;!q.empty();)
	{
		int u=q.front();q.pop();
		if(u==1)
		{
			printf("%d\n",d[u]);
			puts(ans+1);
			return 0;
		}
		for(auto i:g[u])
		{
			int x=i.first,t=i.second;
			if(x==n||d[x])continue;
			if(!len[x][t])len[x][t]=d[u]+1;
			ans[x]=(!t)+'0';
			if(len[x][0]&&len[x][1])d[x]=len[x][t],ans[x]=t+'0',q.push(x);
		}
	}
	puts("-1");
	rep(i,n)if(!len[i][0])ans[i]='0';else ans[i]='1';
	puts(ans+1);
	return 0;
}