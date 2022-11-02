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
        
const int inf = 5e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pii> pers(n + 1);
	vector<int> ind(n + 1);
	iota(all(ind), 0);
	for(int i = 1;i <= n;i++)
		cin >> pers[i].fi >> pers[i].se;
	stable_sort(all(ind), [&](auto v1, auto v2) {return pers[v1].se < pers[v2].se;});
	stable_sort(all(pers), [](auto v1, auto v2) {return v1.se < v2.se;});

	vector<vector<int>> tp(n + 2, vector<int>(n + 2, 0));
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, -inf));
	dp[0][0] = 0;

	for(int i = 1;i <= n;i++) {
		int a = pers[i].fi, b = pers[i].se;
		for(int y = 0;y <= k;y++) {
			dp[i][y] = dp[i - 1][y] + (k - 1) * b;
			if (y != 0) {
				int num = dp[i - 1][y - 1] + a + (y - 1) * b;
				if (dp[i][y] < num) {
					dp[i][y] = num;
					tp[i][y] = 1;
				}
			}
			//cout << i << " " << y << " " << dp[i][y] << endl;
		}
	}

	vector<int> rr(n + 1);

	int c = k;
	for(int i = n;i > 0;i--) {
		rr[i] = tp[i][c];
		c -= rr[i];
	}

	vector<int> q;
	for(int i = 1;i <= n;i++) {
		if (sz(q) < k - 1 && rr[i] == 1) q.emplace_back(ind[i]);
	}
	for(int i = 1;i <= n;i++) {
		if (rr[i] == 0) q.emplace_back(ind[i]), q.emplace_back(-ind[i]);
	}
	for(int i = n;i > 0;i--) {
		if (rr[i] == 1) {
			q.emplace_back(ind[i]);
			break;
		}
	}

	//cout << dp[n][k] << endl;
	cout << sz(q) << endl;
	for(int i : q)
		cout << i << " ";
	cout << endl;
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