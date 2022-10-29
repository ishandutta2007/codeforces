#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
const ll Inf=1e18;
int in[N],out[N],mini[N],ans,mini2[N],deg[N];
vi g[N],e[N];
char s[N];
queue<int> q;
int dfs(int u){
	if(mini[u]<N)return mini[u];
	mini[u]=u;
	for(auto v:g[u]){
		int val=dfs(v);
		if(val<mini[u])mini[u]=val;
	}
	return mini[u];
}
int dfs2(int u){
	if(mini2[u]<N)return mini2[u];
	mini2[u]=u;
	for(auto v:e[u]){
		int val=dfs2(v);
		if(val<mini2[u])mini2[u]=val;
	}
	return mini2[u];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)mini[i]=N,mini2[i]=N;
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		e[v].pb(u);
		deg[v]++;
		in[v]++;
		out[u]++;
	}
	rep(i,1,n+1){
		if(!deg[i])q.push(i);
	}
	int sum=n;
	while(!q.empty()){
		int u=q.front();
		q.pop();--sum;
		for(auto v:g[u]){
			if(--deg[v]==0)q.push(v);
		}
	}
	if(sum)cout<<-1;
	else{
		rep(i,1,n+1){
			if(!in[i])dfs(i);
			if(!out[i])dfs2(i);
		}
		rep(i,1,n+1)if(mini[i]==i&&mini2[i]==i)s[i]='A',++ans;
		else s[i]='E';
		printf("%d\n%s",ans,s+1);
	}
	
}