//sobskdrbhvk
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

const int maxn = 1e5 + 85 - 69,
	  maxl = 18;
int par[maxn][maxl],
	h[maxn],
	stim[maxn],
	ftim[maxn],
	ord[maxn],
	tim, n, sum, k;
vector<int> adj[maxn];
set<int> s;

bool ischild(int u, int v){
	return stim[u] <= stim[v]
		and stim[v] < ftim[u];
}

void dfs(int u = 0){
	ord[tim] = u;
	stim[u] = tim++;
	for(int i = 1; i < maxl and par[u][i - 1] != -1; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for(auto v : adj[u])
		if(v != par[u][0])
			par[v][0] = u, h[v] = h[u] + 1, dfs(v);
	ftim[u] = tim;
}

int lca(int u, int v){
	if(h[u] < h[v])
		swap(u, v);
	for(int i = 0; h[u] - h[v]; i++)
		if(((h[u] - h[v]) >> i) & 1)
			u = par[u][i];
	if(u == v) return u;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int dist(int u, int v){
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

int getval(int u){
	if(sz(s) == 0) return 0;
	auto it = s.lower_bound(stim[u]);
	int nxt = ord[*(it == s.end() ? s.begin() : it)];
	int lst = ord[(it == s.begin() ? *s.rbegin() : *(--it))];
	return dist(lst, u) + dist(u, nxt) - dist(lst, nxt);
}

bool check(int len){
	sum = 0;
	s.clear();
	for(int i = 0; i < len - 1; i++){
		sum += getval(i);
		s.insert(stim[i]);
		//cout << i << " added: " << sum << endl;
	}
	for(int i = len - 1; i < n; i++){
		sum += getval(i);
		s.insert(stim[i]);
		//cout << i << " added: " << sum << endl;
		if(i - len >= 0){
			s.erase(stim[i - len]);
			sum -= getval(i - len);
			//cout << i - len << " removed: " << sum << endl;
		}
		if(sum / 2 < k) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	memset(par, -1, sizeof par);
	dfs();
	int lo = 1,
		hi = n + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}