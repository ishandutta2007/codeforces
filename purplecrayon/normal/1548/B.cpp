#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

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
				jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        b++;
		int dep = 31 - __builtin_clz(b - a);
		return gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<ll> d(n-1);
    for (int i = 0; i < n-1; i++) d[i] = abs(a[i+1]-a[i]);

    RMQ<ll> rmq(d);
    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        int lo = i-1, hi = n-1, mid = (lo+hi)/2;
        while (lo < mid && mid < hi) {
            if (rmq.query(i, mid) != 1) lo = mid;
            else hi = mid;
            mid = (lo+hi)/2;
        }
        ans = max(ans, lo-i+2);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}