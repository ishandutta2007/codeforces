#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> s[i];
    vector<int> dp(n + 1);
    x[0] = 0, y[0] = 0, s[0] = 0;
    dp[0] = 0;
    int answer = 0;
    int a = 0;
    for (int i = 1; i <= n; ++i) {
        int j = lower_bound(all(x), y[i]) - x.begin();
        int need = sub(x[i], x[i - 1]);
        need = add(need, sub(x[j], y[i]));
        if (j != i) {
            need = add(need, add(dp[j], a));
            need = add(need, sub(x[i], x[i - 1]));
        }
        int to = sub(need, sub(x[i], x[i - 1]));
        a = add(a, need);
        dp[i] = sub(to, a);
        answer = add(answer, sub(x[i], x[i - 1]));
        if (s[i]) {
            answer = add(answer, add(dp[i], a));
        }
    }
    answer = add(answer, 1);
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}