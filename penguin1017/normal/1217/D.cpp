#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x)) 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair 
using namespace std;
const int N=(int)5e3+9;
int deg[N],ans[N],vis[N];
vector<pii> g[N];
void dfs(int u){
	vis[u]=1;
	for(auto w:g[u]){
		int id=w.se,v=w.fi;
		if(!vis[v])dfs(v);
		if(u<v)ans[id]=1;
		else ans[id]=2;
	}
	return;
} 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(mp(v,i));
		deg[v]++;
	}
	queue<int> q;
	rep(i,1,n+1)if(!deg[i])q.push(i);
	while(!q.empty()){
		int u=q.front();
		vis[u]=1;
		q.pop();
		for(auto v:g[u]){
			deg[v.fi]--;
			ans[v.se]=1;
			if(!deg[v.fi])q.push(v.fi);
		}
	}
	rep(i,1,n+1)if(!vis[i])dfs(i);
	int sum=0;
	rep(i,0,m)sum=max(sum,ans[i]);
	printf("%d\n",sum);
	rep(i,0,m)printf("%d ",ans[i]);
}