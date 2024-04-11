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
vector<pii> g[N];
int ans[N],deg[N],cnt;
void dfs(int u,int f){
	for(auto w:g[u]){
		if(w.fi==f)continue;
		deg[w.fi]=deg[u]+1;
		dfs(w.fi,u);
	}
}
bool dfs2(int u,int f){
	bool flag=0;
	for(auto w:g[u]){
		if(w.fi==f)continue;
		if(dfs2(w.fi,u)){
			if(ans[w.se]==-1)ans[w.se]=cnt--;
		}
		if(ans[w.se]!=-1)flag=1;
	}
	return flag;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb({v,i});
		g[v].pb({u,i}); 
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	cnt=n-2;
	dfs(1,0);
	int p=1;
	rep(i,1,n+1)if(deg[i]>deg[p])p=i;
	deg[p]=0;
	dfs(p,0);
	int e=1;
	rep(i,1,n+1)if(deg[i]>deg[e])e=i;
	memset(ans,-1,sizeof ans);
	ans[g[e][0].se]=0;
	ans[g[p][0].se]=1;
	dfs2(p,0);
	cnt=2;
	rep(i,0,n-1)if(ans[i]==-1)ans[i]=cnt++;
	rep(i,0,n-1)printf("%d\n",ans[i]);
}