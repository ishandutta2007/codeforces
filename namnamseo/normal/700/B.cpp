#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ cin>>x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

const int max_n = 200010;

vector<int> edge[max_n];
int par[20][max_n];
int tin[max_n];
int depth[max_n];
int nt;

void dfs(int x){
	tin[x]=++nt;
	for(int y:edge[x]){
		if(par[0][x]==y) continue;
		par[0][y]=x;
		depth[y]=depth[x]+1;
		dfs(y);
	}
}

int lca(int a,int b){
	if(depth[a]>depth[b]) swap(a,b);
	int df=depth[b]-depth[a];
	for(int i=18; 0<=i; --i) if(1&(df>>i)) b=par[i][b];
	for(int i=18; 0<=i; --i) if(par[i][a] != par[i][b])
		a=par[i][a], b=par[i][b];
	if(a!=b) a=par[0][a];
	return a;
}

int main(){
	int k;
	int n; read(n, k);
	vector<int> pts; pts.reserve(k);
	for(int i=1; i<=2*k; ++i){
		int x; read(x); pts.pb(x);
	}
	for(int i=1; i<n; ++i){
		int a,b; read(a,b); edge[a].pb(b); edge[b].pb(a);
	}
	dfs(1);
	for(int i=1; i<=18; ++i) for(int j=1; j<=n; ++j)
		par[i][j]=par[i-1][par[i-1][j]];

	sort(all(pts), [&](int a,int b){
		return tin[a]<tin[b];
	});

	ll ans=0;
	for(int i=0; i<k; ++i){
		int a=pts[i], b=pts[k+i], c=lca(a,b);
		ans += depth[a]+depth[b]-2*depth[c];
	}

	printf("%I64d\n", ans);

	return 0;
}