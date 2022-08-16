#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

struct MaxValue {
    ll x;

    MaxValue(): x(-INF) { }
    MaxValue(ll _x): x(_x) { }

    friend MaxValue operator + (const MaxValue& a, const MaxValue& b) {
        return MaxValue(max(a.x, b.x));
    }
};
struct MaxPair {
    ll one, two, ans;

    MaxPair(): one(-INF), two(-INF), ans(-INF) { }
    MaxPair(ll a, ll b): one(a), two(b), ans(a + b) { }

    friend MaxPair operator + (const MaxPair& a, const MaxPair & b) {
        MaxPair ans;
        ans.one = max(a.one, b.one);
        ans.two = max(a.two, b.two);
        ans.ans = max({a.ans, b.ans, a.one + b.two});
        return ans;
    }
};


template <class T>
struct Tree {
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0) : s(2*n, T()), n(n) {}
	void upd(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e]
        e++;
		T ra = T(), rb = T();
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


int n, q;
ll a[3][N], sum[3][N], dp[N][2], end_cost[N];
vector<ar<int, 2>> qr[N];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k, --l, --r;
        qr[r].push_back({l, k});
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = a[i][j];
            if (j) sum[i][j] += sum[i][j-1];
        }
    }

    auto get_sum = [&](int l, int r) {
        if (l > r) return 0LL;
        return sum[1][r] - (l ? sum[1][l-1] : 0);
    };
    auto cost_end = [&](int i) {
        return sum[2][n-1] - (i ? sum[2][i-1] : 0);
    };
    for (int i = 0; i < n; i++) end_cost[i] = cost_end(i);

    // dp[i][0/1] -> 
    //      answer for [0, i], whether I'm previously available or not
    Tree<MaxValue> edge(n);
    Tree<MaxPair> trans(n);
    Tree<MaxValue> dp_store(n);

    ll ans = -INF;
    for (int i = 0; i < n; i++) {
        dp[i][1] = sum[0][i] + a[1][i];
        dp[i][0] = -INF;
        for (auto [l, k] : qr[i]) {
            /*
            for (int j = l; j < i; j++) {
                // ll cost = dp[j][1] + get_sum(j+1, i) - k;
                ll cost = dp[j][1] + sum[1][i] - sum[1][j] - k;
                dp[i][0] = max(dp[i][0], cost);
                dp[i][1] = max(dp[i][1], cost);
            }
            */
            if (l < i) {
                ll cur_dp = dp_store.qry(l, i-1).x + sum[1][i] - k;
                dp[i][0] = max(dp[i][0], cur_dp);
                dp[i][1] = max(dp[i][1], cur_dp);
            }
            dp[i][0] = max(dp[i][0], dp[i][1] - k);

            if (l) {
                ll cost = dp[l-1][0] + get_sum(l, i) - k;
                dp[i][0] = max(dp[i][0], cost);
                dp[i][1] = max(dp[i][1], cost);

                const ll base = dp[l-1][0] - sum[1][l-1] - k;
                ans = max(ans, base + edge.qry(l, i).x);
                /*
                for (int end = l; end <= i; end++) { // range query
                    ans = max(ans, base + sum[1][end] + end_cost[end]);
                }
                */
            }

            if (l < i) {
                ll cur = trans.qry(l, i-1).ans;
                /*
                ll cur = -INF;
                for (int j = l; j < i; j++) {
                    for (int end = j; end < i; end++) {
                        ll one = dp[j][1] - sum[1][j];
                        ll two = sum[1][end] + end_cost[end];
                        cur = max(cur, one + two);
                        // ans = max(ans, dp[j][1] + sum[1][end] - sum[1][j] - k + end_cost[end]);
                        // ans = max(ans, dp[j][1] + get_sum(j + 1, end) - k + cost_end(end));
                    }
                }
                */
                ans = max(ans, cur - k);
            }
        }
        ans = max(ans, dp[i][0] + cost_end(i));
        edge.upd(i, MaxValue(sum[1][i] + end_cost[i]));
        trans.upd(i, MaxPair(dp[i][1] - sum[1][i], sum[1][i] + end_cost[i]));
        dp_store.upd(i, MaxValue(dp[i][1] - sum[1][i]));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}