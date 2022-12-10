//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
LL frm[maxn],
   too[maxn],
   wei[maxn],
   dis[maxn],
   par[maxn],
   ty[maxn],
   n, m;
bool mark[maxn];
vector<int> adj[maxn];
vector<pii> ans;
set<pll> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		frm[i] = fi, too[i] = se, ty[i] = th, wei[i] = 2e5 + 1 - th;
		adj[fi].PB(i);
		adj[se].PB(i);
	}
	memset(dis, 63, sizeof dis);
	dis[0] = 0;
	s.insert(MP(0, 0));
	memset(par, -1, sizeof par);
	while(sz(s)){
		int u = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[u]){
			int v = too[e]^frm[e]^u,
				w = wei[e];
			if(dis[u] + w < dis[v]){
				s.erase(MP(dis[v], v));
				dis[v] = dis[u] + w;
				s.insert(MP(dis[v], v));
				par[v] = e;
			}
		}
	}
	int u = n - 1;
	while(~par[u]){
		mark[par[u]] = true;
		u = frm[par[u]]^too[par[u]]^u;
	}
	for(int i = 0; i < m; i++)
		if(mark[i] and ty[i] == 0)
			ans.PB(MP(i, 1));
		else if(!mark[i] and ty[i] == 1)
			ans.PB(MP(i, 0));
	cout << sz(ans) << '\n';
	for(auto p : ans)
		cout << 1+frm[p.L] << ' ' << 1+too[p.L] << ' ' << p.R << '\n';
	return 0;
}