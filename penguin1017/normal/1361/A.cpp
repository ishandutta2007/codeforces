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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int id[N],vis[N];
vi g[N];
pii p[N];
bool flag[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ok=0;
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	rep(i,1,n+1){
		scanf("%d",&id[i]);
		p[i]={id[i],i};
	}
	sort(p+1,p+1+n);
	rep(i,1,n+1){
		int val=p[i].fi,u=p[i].se;
		rep(j,1,val+1)vis[j]=0;
		for(auto v:g[u]){
			if(!flag[v])continue;
			vis[id[v]]=1;
		}
		rep(j,1,val)if(!vis[j])ok=1;
		if(vis[val])ok=1;
		if(ok)break;
		flag[u]=1;
	}
	if(ok){
		cout<<-1;
		return 0;
	}
	rep(i,1,n+1)printf("%d ",p[i].se);
}