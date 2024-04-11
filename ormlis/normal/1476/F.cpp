#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template<class T, class Fun = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;

    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<T>(n));
        rep(i, n) sp[0][i] = a[i];
        rep(j, lg - 1) {
            rep(i, n) {
                if (i + (1 << (j + 1)) > n) break;
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    T get(int l, int r) {
        int k = __lg(r - l);
        return f(sp[k][l], sp[k][r - (1 << k)]);
    }
};

void solve() {
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    vector<int> a(n);
    rep(i, n) a[i] = p[i] + i;
    SparseTable st(a, [&](const int &x, const int &y) { return max(x, y); });
    //
    vi dp(n + 1, -2);
    vi pr(n + 1, -2);
    vi tt(n + 1, -1);
    dp[0] = -1;
    rep(i, n) {
        int value = dp[i];
        if (i && p[i] && value + 1 >= i - p[i]) {
            // to_left
            int l;
            {
                int L = max(0, i - p[i]) - 2;
                int R = i - 1;
                if (L == -2) R = -1;
                while (R - L > 1) {
                    int mid = (L + R) / 2;
                    if (dp[mid] + 1 >= i - p[i]) {
                        R = mid;
                    } else {
                        L = mid;
                    }
                }
                l = R + 1;
            }
            int r = i;
            int mx;
            if (l < r) {
                mx = st.get(l, r);
            } else {
                mx = i - 1;
            }
            if (dp[i] < mx) {
                dp[i] = mx;
                pr[i] = 0;
                tt[i] = l;
            }
        }
        if (value >= i) {
            if (dp[i] < i + p[i]) {
                dp[i] = i + p[i];
                pr[i] = 1;
            }
        }
        dp[i + 1] = dp[i];
        pr[i + 1] = 2;
    }
    if (dp[n] < n - 1) {
        cout << "NO\n";
        return;
    }
    int f = n - 1;
    str result;
    while (f >= 0) {
        if (pr[f] != 0) {
            result += 'R';
            f--;
            continue;
        }
        result += 'L';
        int to = tt[f];
        f--;
        while (f >= to) {
            result += 'R';
            f--;
        }
    }
    cout << "YES\n";
    reverse(all(result));
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}