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


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(n);
    vector<int> mid(n);
    vector<int> sm(n);
    vector<int> mmn(n);
    range(i, n) {
        string s;
        cin >> s;
        int p = 0;
        mid[i] = s.size() + 1;
        cnt[i].resize(mid[i] * 2 + 5);
        int mn = 0;
        for (auto &c : s) {
            if (c == '(') {
                p++;
            } else {
                p--;
            }
            mn = min(mn, p);
            if (mn == p) cnt[i][p + mid[i]]++;
        }
        sm[i] = p;
        mmn[i] = mn;
    }
    int ans = 0;
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    range(mask, 1 << n) {
        if (dp[mask] == -1) continue;
        int cur = 0;
        range(i, n) {
            if (mask & (1 << i)) cur += sm[i];
        }
        range(j, n) {
            if (mask & (1 << j)) continue;
            int e = -cur + mid[j];
            int res = dp[mask];
            if (e >= 0 && e < cnt[j].size()) res += cnt[j][e];
            ans = max(ans, res);
            if (cur + mmn[j] >= 0) {
                dp[mask | (1 << j)] = max(dp[mask | (1 << j)], res);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}