#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

ll 		 deg[MAX];
vector<ll> g[MAX];
ll		dt[MAX];
vector<int> bfs;
int cntr;
bool dfs(int hd){
	bool nd = 1;
	for(auto hr : g[hd]){
		if(dt[hd] + 1 < dt[hr])
			dt[hr] = dt[hd] + 1, nd&=dfs(hr);
	}
	if( (g[hd].size() == 3 && hd != cntr ) || (g[hd].size()==2) )
		 nd = 0;
	return nd;
}

void deal(){
	int n, k;
	cin>>n>>k;
	if(n==1){
		cout<<"No";
		return;
	}
	fori(n-1){
		int u,v;
		cin>>u>>v; --u, --v;
		g[u].pb(v), g[v].pb(u);
		deg[u]++, deg[v]++;
	}
	fori(n)
		if(deg[i] == 1)
			bfs.pb(i);
	fori(bfs.size()){
		int hd = bfs[i];
		for(auto hr : g[hd]){
			--deg[hr];
			if(deg[hr]==1)
				bfs.pb(hr);
		}
	}
	cntr = bfs[bfs.size()-1];
	fori(MAX)
		dt[i] = MAX;
	dt[cntr] = 0;
	if(!dfs(cntr))
		cout<<"No";
	else{
		fori(n)
			if(g[i].size() == 1 && dt[i]!=k){
				cout<<"No";
				return;
			}
		cout<<"Yes";
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1