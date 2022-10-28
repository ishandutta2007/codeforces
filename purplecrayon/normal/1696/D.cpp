#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

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
template<class T>
struct RMQ_MAX {
	vector<vector<T>> jmp;
	RMQ_MAX(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};



void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> big(n, n), small(n, n);
    {
        vector<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (sz(st) && a[st.back()] < a[i]) st.pop_back();
            if (sz(st)) big[i] = st.back();
            st.push_back(i);
        }
    }
    {
        vector<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (sz(st) && a[st.back()] > a[i]) st.pop_back();
            if (sz(st)) small[i] = st.back();
            st.push_back(i);
        }
    }

    vector<int> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]] = i;
    RMQ mn(a);
    RMQ_MAX mx(a);

    vector<int> dp(n, MOD); dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        int use = max(big[i], small[i])-1;
        if (big[i] > small[i]) {
            dp[i] = min(dp[i], 1 + dp[loc[mn.query(i, use)]]);
        } else {
            dp[i] = min(dp[i], 1 + dp[loc[mx.query(i, use)]]);
        }
    }
    cout << dp[0] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}