#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

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
	T qry(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
bool is_perm(vector<int> a) {
    int n = sz(a);
    for (auto& c : a) {
        c--;
        if (c < 0 || c >= n) return 0;
    }
    vector<bool> vis(n);
    for (auto c : a) vis[c] = 1;
    return *min_element(vis.begin(), vis.end());
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    
    RMQ rmq(a);

    auto v = [&](int k) -> bool {
        vector<int> v;
        for (int i = 0; i+k <= n; i++) v.push_back(rmq.qry(i, i+k-1));
        return is_perm(v);
    };

    int lo = 1, hi = n+1, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << is_perm(a);
        else cout << bool(i >= hi);
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}