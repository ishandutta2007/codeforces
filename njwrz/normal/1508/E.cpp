#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,a[300005];
V<int> v[300005],g[300005],tv[300005];
int fa[300005],siz[300005],dep[300005],dfn[300005],it[300005];
bool cmp(int x,int y){
	RE a[x]<a[y];
}
void dfs(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		fa[u]=x;
		dep[u]=dep[x]+1;
		dfs(u,x);
		siz[x]+=siz[u];
		g[x].PB(u);
	}
	sort(ALL(g[x]),cmp);
	tv[x]=g[x];reverse(ALL(tv[x]));
}
int cnt=0;
void get(int x){
	dfn[x]=++cnt;
	for(auto u:g[x])get(u);
}
int vis[300005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	RE x;
}
set<int> s[300005];
int ans=0;
void dfs2(int x){
	if(dfn[x]>=a[1])s[x].emplace(dfn[x]);
	for(auto u:g[x]){
		dfs2(u);
		if(s[u].size()>s[x].size())swap(s[u],s[x]);
		for(auto tu:s[u])s[x].emplace(tu);
	}
	if(a[x]>=a[1]){
		if(s[x].empty()||(*s[x].rbegin())!=a[x]){
			cout<<"NO\n";exit(0);
		}
		s[x].erase(a[x]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],it[a[i]]=i;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	get(1);
	V<int> s;
	rep(i,1,a[1]){
		ans+=dep[it[i]];
		if(s.empty()){
			V<int> now;
			int p=it[i];now.PB(p);
			while(p!=1){
				p=fa[p];
				now.PB(p);
			}
			reverse(ALL(now));
			rep(i,0,(int)now.size()-1){
				if(now[i+1]!=tv[now[i]].back()){
					cout<<"NO\n";RE 0;
				}
				tv[now[i]].pop_back();
			}
			s=now;
			for(auto u:now)vis[u]=1;
		}else{
			int t=lca(it[i-1],it[i]);
			if(t==it[i-1]){
				cout<<"NO\n";RE 0;
			}
			while(s.back()!=t){
				if(siz[s.back()]!=i-vis[s.back()]){
					if(i==a[1]-1&&t==it[i]){
						s.pop_back();continue;
					}
					cout<<"NO\n";RE 0;
				}
				s.pop_back();
			}
			int p=it[i];
			V<int> v;
			while(p!=s.back())v.PB(p),p=fa[p];
			for(auto u:v)vis[u]=i;
			reverse(ALL(v));
			for(auto u:v)s.PB(u);
			rep(i,s.size()-v.size(),s.size()){
				if(s[i]!=tv[s[i-1]].back()){
					cout<<"NO\n";RE 0;
				}
				tv[s[i-1]].pop_back();
			}
		}
	}
	dfs2(1);
	cout<<"YES\n"<<ans<<'\n';
	FOR(i,1,n)cout<<dfn[i]<<' ';
	RE 0;	
}