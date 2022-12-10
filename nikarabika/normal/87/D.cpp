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
LL ans[maxn],
   cnt[maxn];
int h[maxn],
	par[maxn],
	frm[maxn],
	too[maxn],
	len[maxn],
	n;
vector<int> adj[maxn],
	vec[maxn],
	all;

void dfs(int u, int p = -1){
	for(auto e : adj[u]){
		int v = frm[e]^too[e]^u;
		if(v != p){
			h[v] = h[u] + 1;
			dfs(v, u);
		}
	}
	return;
}

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]);}

void merge(int u, int v){
	if((u = root(u)) == (v = root(v))) return;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return;
}

bool cmp(int i, int j){
	return h[too[i]] > h[too[j]];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> frm[i] >> too[i] >> len[i];
		frm[i]--, too[i]--;
		adj[frm[i]].PB(i);
		adj[too[i]].PB(i);
		all.PB(len[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 1; i < n; i++)
		vec[len[i] = lower_bound(all(all), len[i]) - all.begin()].PB(i);
	dfs(0);
	for(int i = 1; i < n; i++)
		if(h[frm[i]] > h[too[i]])
			swap(frm[i], too[i]);
	for(int i = 0; i < sz(all); i++)
		sort(all(vec[i]), cmp);
	for(int i = 0; i < sz(all); i++){
		for(int j = 0; j < sz(vec[i]); j++){
			int eid = vec[i][j];
			cnt[j] = -par[root(too[eid])];
			merge(too[eid], frm[eid]);
		}
		LL szall = 0;
		for(int j = 0; j < sz(vec[i]); j++)
			ans[vec[i][j]] = -2LL * cnt[j] * (cnt[j] + par[root(too[vec[i][j]])]);
	}
	LL mx = *max_element(ans+1, ans + n);
	cout << mx << ' ' << count(ans+1, ans + n, mx) << '\n';
	for(int i = 1; i < n; i++)
		if(ans[i] == mx)
			cout << i << ' ';
	cout << '\n';
	return 0;
}