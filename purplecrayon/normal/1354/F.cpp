#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;

pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

void solve(){
    int n, k; cin >> n >> k;
    vector<ar<int, 2>> a(n);
    for (auto& it : a) cin >> it[0] >> it[1];

    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < k-1) cost[i][j] = a[i][0]+j*a[i][1];
            else if (j < n-1) cost[i][j] = a[i][1]*(k-1);
            else cost[i][j] = a[i][0]+a[i][1]*(k-1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = -cost[i][j];
        }
    }
    auto match = hungarian(cost).second;
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[match[i]] = i;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i < k-1) ans.push_back(b[i]+1);
        else if (i < n-1) ans.push_back(b[i]+1), ans.push_back(-(b[i]+1));
        else ans.push_back(b[i]+1);
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}