#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


void solve() {
    int n, c; cin >> n >> c;
    vector<ll> a(n); for (auto& x : a) cin >> x;

    RMQ rmq(a);
    if (c > n) {
        ll ans = 0;
        for (int x : a) ans += x;
        cout << ans << '\n';
        return;
    }
    vector<ll> ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = a[i] + (i ? ps[i-1] : 0);
    }

    auto sum = [&](int L, int R) {
        return ps[R] - (L ? ps[L-1] : 0);
    };

    vector<ll> dp(n + 1);
    for (int i = n-1; i >= 0; i--) {
        dp[i] = dp[i+1] + a[i];
        if (i + c <= n) {
            dp[i] = min(dp[i], dp[i + c] + sum(i, i + c - 1) - rmq.query(i, i + c - 1));
        }
    }
    cout << dp[0] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}