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
#define MAX (int)(2*pow(10,7) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;


#define N (int)(pow(10,6) + 10)

namespace scc{
		
	int low[N],vis[N],scomp[N],scompNum,I;
	vector<int> adj[N]; stack<int> verts;
	void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
	  for (int v : adj[u]) {
	    if (!vis[v]) scc(v);
	    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
	  if (vis[u] <= low[u]) { int v;
	    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; }while (v != u);
	    ++scompNum; }}
	void get_scc(int n) {
	  memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
	  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
};

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};

void deal(){
	ll n, m;
	cin>>n>>m;
	vector<vector<char> > arr(n, vector<char>(m));
	vector<vector<ll> > num(n, vector<ll>(m, 0));
	
	
	fori(n){
		forj(m){
			cin>>arr[i][j];
			num[i][j] = i*m + j;
		}
	}
	
	fori(m){
		ll ed;
		cin>>ed;
	}
	
	fori(n){
		forj(m){
			fork(4){
				ll xi = dx[k], yi = dy[k];
				ll i1 = i + xi, j1 = j + yi;
				if(i1 >-1 && j1 > -1 && i1 < n && j1 < m){
					ll n1 = num[i][j], n2 = num[i1][j1];
					if(xi){
						if(i1 > i){
							scc::adj[n1].pb(n2);
						}
						else{
							if(arr[i][j] == '#' && arr[i1][j1] == '#'){
								scc::adj[n1].pb(n2);
							}
						}
					}
					else{
						if(arr[i1][j1] == '#'){
							scc::adj[n1].pb(n2);
						}
					}
				}
			}
		}
	}
	
	
	scc::get_scc(n*m);
	vector<bool> in(n*m, 0);
	vector<bool> legit(n*m, 0);
	vector<bool> active(n*m, 0);
	
	fori(n){
		forj(m){
			if(arr[i][j] == '#'){
				legit[scc::scomp[num[i][j]]] = 1;
			}
		}
	}
	
	vector<vector<ll> > g(n*m);
	
	fori(n*m){
		for(auto& hr : scc::adj[i]){
			if(scc::scomp[i] != scc::scomp[hr]){
				g[scc::scomp[i]].pb(scc::scomp[hr]);
			}
		}
	}
	
	ll tot = 0;
	
	for(ll i = scc::scompNum-1; i>-1; i--){
		if(active[i]){
			for(auto& el : g[i]){
				active[el] = 1;
			}
		}
		else{
			if(legit[i]){
				++tot;
				for(auto& el : g[i]){
					active[el] = 1;
				}
			}
		}
	}
	
	cout<<tot;
	
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}