#include <bits/stdc++.h>
#define MAXN 500007
using namespace std;
vector<int> g[MAXN];
int p[MAXN],v[MAXN];
bool vi[MAXN],im[MAXN];
pair<int,int> a[MAXN];
int main()
{
	int n,m; scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	for(int i=1;i<=n;i++)
	{
		int t; scanf("%d",&t);
		a[i]={t,i};
		v[i]=t;
	}
	sort(a+1,a+n+1);
	bool rd=true;
	for(int i=1;i<=n && rd;i++)
	{
		int u=a[i].second,val=a[i].first;
		vi[u]=true; p[i]=u;
		for(int j=0;j<g[u].size();j++) if(vi[g[u][j]]) im[v[g[u][j]]]=true;
		if(im[val]) {rd=false; break;}
		for(int j=1;j<val;j++) if(!im[j]) {rd=false; break;}
		for(int j=0;j<g[u].size();j++) if(vi[g[u][j]]) im[v[g[u][j]]]=false;
	}
	if(!rd) printf("-1");
	else for(int i=1;i<=n;i++) printf("%d ",p[i]);
}