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
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e4 + 5;
const int LG = 20;


void solve() {
    int n;
    cin >> n;
    const int C = 10;
    const int M = 10;
    const int T = (C * C * C * 2);
    vvi dp(T, vi(M, INFi));
    int A, B;
    cin >> A >> B;
    dp[1][A] = A;
    vi b(5);
    b[0] = 1;
    b[1] = 2;
    for (int i = 2; i <= 4; ++i) b[i] = b[i - 1] * C;

    auto get_bit = [&](int mask, int i) {
        int val = (mask % b[i + 1]) / b[i];
        if (i == 0) return B * val;
        return val;
    };

    auto set_bit = [&](int mask, int i, int x) {
        if (i == 0) {
            mask |= 1;
            if (x == 0) mask ^= 1;
            return mask;
        }
        int was = get_bit(mask, i);
        return mask + b[i] * (x - was);
    };

    auto check = [&]() {
        set<ar<int, 3>> q;
        rep(mask, T) {
            rep(e, M) {
                if (e == 0) continue;
                if (dp[mask][e] == INFi) continue;
                q.insert({dp[mask][e], mask, e});
            }
        }
        auto upd = [&](int mask, int e, int val) {
            if (dp[mask][e] > val) {
                q.erase({dp[mask][e], mask, e});
                dp[mask][e] = val;
                q.insert({dp[mask][e], mask, e});
            }
        };
        while (!q.empty()) {
            auto[val, mask, e] = *q.begin();
            q.erase(q.begin());
            int mask2 = mask;
            int val2 = val;
            rep(t, 4) {
                if (get_bit(mask, t) == e) {
                    val2++;
                    mask2 = set_bit(mask2, t, 0);
                }
            }
            upd(mask2, e, val2);
            val2++;
            if (e + 1 < M) {
                upd(mask2, e + 1, val2);
            }
            if (e - 1 >= 1) {
                upd(mask2, e - 1, val2);
            }
        }
    };

    check();
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        vvi dp2(T, vi(M, INFi));
        rep(mask, T) {
            int mask2 = 0;
            int cnt = 0;
            rep(t, 4) {
                int w = get_bit(mask, t);
                if (w == 0) continue;
                cnt++;
                mask2 *= 10;
                mask2 += w;
            }
            if (cnt == 4) continue;
            mask2 *= 2;
            mask2 += 1;
            dp2[mask2][a] = min(dp2[mask2][a], dp[mask][a] + 1);
        }
        swap(dp, dp2);
        A = a;
        B = b;
        check();
    }
    int ans = INFi;
    rep(e, M) {
        ans = min(ans, dp[0][e]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}