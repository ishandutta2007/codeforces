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

const int maxn = 3000 + 85 - 69;
int frm[maxn],
	too[maxn],
	n, curans, ans;
vector<int> adj[maxn];

int get_ans(int u, int p = -1){
	int ret = 0;
	for(auto e : adj[u]){
		int v = frm[e]^too[e]^u,
			w = frm[e]==v;
		if(v == p) continue;
		ret += w + get_ans(v, u);
	}
	return ret;
}

void dfs(int u, int p = -1, int dp = 0, int sum = 0){
	smin(ans, curans);
	for(auto e : adj[u]){
		int v = frm[e]^too[e]^u,
			w = frm[e]==v;
		if(v == p) continue;
		int pd = min(sum + w, dp + 1 - w);
		curans += pd - dp - w;
		dfs(v, u, pd, sum + w);
		curans -= pd - dp - w;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		frm[i] = fi, too[i] = se;
		adj[fi].PB(i);
		adj[se].PB(i);
	}
	ans = n - 1;
	for(int i = 0; i < n; i++){
		curans = get_ans(i);
		dfs(i);
	}
	cout << ans << '\n';
	return 0;
}