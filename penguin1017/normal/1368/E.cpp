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
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
vi g[N];
int vis[N],deg[N],ans[N],dep[N];
queue<int> q;
int main(){
	int n,m;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,0,m){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].pb(v);
			deg[v]++;
		}
		rep(i,1,n+1){
			if(deg[i]==0){
				q.push(i);
			}
		}
		int cnt=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto v:g[u]){
				if(vis[v])continue;
				if(!dep[u]){
					dep[v]=1;
					if(--deg[v]==0)q.push(v);
				}
				else{
					ans[cnt++]=v;
					vis[v]=1;
					for(auto w:g[v])if(--deg[w]==0)q.push(w);
				}
			}
			
		}
		printf("%d\n",cnt);
		rep(i,0,cnt)printf("%d ",ans[i]);
		printf("\n");
		rep(i,1,n+1)g[i].clear(),vis[i]=0,deg[i]=0,dep[i]=0;
		while(!q.empty())q.pop();
	}
}