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
//void read(ll& x){ scanf("%I64d",&x); }
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int n;

vector<int> edge[100010];

int par[100010];
int siz[100010];

void dfs(int x){
	siz[x]=1;
	for(int y:edge[x]) if(par[x]!=y){
		par[y]=x;
		dfs(y);
		siz[x] += siz[y];
	}
}

double dist[100010];
void dfs2(int x){
	int cs=siz[x]-1;
	for(int y:edge[x]) if(par[y]==x){
		dist[y] = dist[x] + 1 + ((cs - siz[y]) * 0.5);
		dfs2(y);
	}
}

int main(){
	read(n);
	for(int i=2; i<=n; ++i){
		int p; read(p);
		edge[p].pb(i);
		edge[i].pb(p);
	}
	dfs(1);
	dist[1]=1;
	dfs2(1);
	for(int i=1; i<=n; ++i) printf("%.15f ",dist[i]);
	return 0;
}