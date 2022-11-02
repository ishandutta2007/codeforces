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
        
const int inf = 1e9 + 7;
const int max_n = (1 << 19);

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), ans(q), le(q);
	vector<vector<int>> ri(n + 1);
	for(int i = 1;i <= n;i++)
		cin >> a[i], a[i] = i - a[i];

	for(int i = 0;i < q;i++) {
		int x, y;
		cin >> x >> y;
		le[i] = x + 1;
		ri[n - y].emplace_back(i);
	}

	vector<int> bit(n + 1);

	int global = 0;
	for(int r = 1;r <= n;r++) {
		int targ = a[r];
		if (targ >= 0) {
			int pos = 0, cur = global;
			for(int jump = 1 << __lg(n);jump >= 1;jump /= 2) {
				if (pos + jump <= r && cur - bit[pos + jump] >= targ)
					pos += jump, cur -= bit[pos];
			}

			global++;
			for(int i = pos + 1;i <= n;i += i & -i) {
				++bit[i];
			}
		}

		for(int i : ri[r]) {
			ans[i] = global;
			for(int j = le[i];j > 0;j -= j & -j) {
				ans[i] -= bit[j];
			}
		}
	}
	for(int i = 0;i < q;i++)
		cout << ans[i] << '\n';
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}