#include <bits/stdc++.h>
       
using namespace std;
       
       
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
       
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
        
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
       
const int inf = 2e9 + 7;
const int max_n = 2e5 + 3;

int n;
vector<int> gr[max_n];
int dist[max_n], par[max_n], dp[max_n], a[max_n];

void solve() {

	cin >> n;

	for(int i = 0;i < n;i++)
		gr[i].clear(), dp[i] = dist[i] = 0;


	for(int i = 1;i < n;i++) {
		int v;
		cin >> v;
		gr[--v].emplace_back(i);
		gr[i].emplace_back(v);
	}
	for(int i = 1;i < n;i++)
		cin >> a[i];

	deque<int> bfs = {0};
	dist[0] = 1;
	deque<int> b;

	auto f = [&]() {
		if (sz(b) == 1) return;

		int mx1 = -inf, mx2 = -inf;
		for(int v : b) {
			chkmax(mx1, dp[par[v]] + a[v]);
			chkmax(mx2, dp[par[v]] - a[v]);
		}

		int mn = inf, mx = -inf;
		for(int v : b) 
			chkmin(mn, a[v]), chkmax(mx, a[v]);
		//cout << "mn mx " << mx1 << " " << mx2 << " " << mn << " " << mx << endl;
		for(int v : b) {
			dp[v] = dp[par[v]] + max(a[v] - mn, mx - a[v]);
			chkmax(dp[v], mx1 - a[v]);
			chkmax(dp[v], mx2 + a[v]);
		}
	};

	while(sz(bfs)) {
		int v = bfs.front();
		bfs.pop_front();
		if (sz(b) && dist[v] != dist[b.back()]) {
			f();
			b.clear();
		}
		b.emplace_back(v);

		for(int to : gr[v]) {
			if (dist[to] != 0) continue;
			par[to] = v;
			dist[to] = dist[v] + 1;
			bfs.emplace_back(to);
		}
	} 
	f();
	int res = 0;
	for(int i = 0;i < n;i++) {
		chkmax(res, dp[i]);
	}
	cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--)
    	solve();
}