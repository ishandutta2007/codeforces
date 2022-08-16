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

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;

    RMQ rmq(a);
    auto v = [&](int x){
        x++;
        int p = -1;
        for (int i = 0; i < n; i++) {
            int v = -1;
            if (i+x > n) {
                v = gcd(rmq.query(i, n-1), rmq.query(0, x-(n-i)-1));
            } else {
                v = rmq.query(i, i+x-1);
            }
            if (!i) p = v;
            else {
                if (p != v) return 0;
            }
        }
        return 1;
    };

    int lo = -1, hi = n, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    cout << hi << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}