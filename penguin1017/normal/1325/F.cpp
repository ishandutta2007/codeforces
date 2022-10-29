#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
vi g[N]; 
int ans[N],fa[N],cnt,Sqr,deg[N],dep[N],vis[N],flag,s,t;
priority_queue<pii,vector<pii>,greater<pii>> PQ;
void dfs(int u){
	for(auto v:g[u]){
		if(v==fa[u])continue;
		if(dep[v]){
			if(dep[u]-dep[v]+1>=Sqr){
				cnt=dep[u]-dep[v]+1,flag=1,s=u,t=v;
				return;
			}
			continue;
		}
		dep[v]=dep[u]+1,fa[v]=u,dfs(v);
		if(flag)return;
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	Sqr=sqrt(n-0.5)+1;
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
		deg[u]++,deg[v]++;
	}
	rep(i,1,n+1)PQ.push({deg[i],i});
	while(PQ.size()){
		pii w=PQ.top();PQ.pop();
		int u=w.se;
		if(vis[u])continue;
		vis[u]=1;
		ans[cnt++]=u;
		for(auto v:g[u]){
			if(vis[v])continue;
			vis[v]=1;
			for(auto x:g[v]){
				if(vis[x])continue;
				deg[x]--;PQ.push({deg[x],x});
			}
		}
	}
	if(cnt>=Sqr){
		cout<<1<<endl;
		rep(i,0,Sqr)printf("%d ",ans[i]);
		return 0;
	}
	cout<<2<<endl;
	dep[1]=1;
	dfs(1);
	cout<<cnt<<endl;
	while(s!=t){
		printf("%d ",s);
		s=fa[s];
	}
	printf("%d",t);
}