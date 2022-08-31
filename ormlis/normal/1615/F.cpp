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
const int maxN = 605;
const int LG = 20;

const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int T = n + 2;
    vi dp(T * 2 + 1, 0), cnt(T * 2 + 1, 0);
    cnt[T] = 1;
    rep(i, n) {
        vi dp2(T * 2 + 1, 0);
        vi cnt2(T * 2 + 1, 0);
        rep(mask, 4) {
            int A = mask & 1;
            int B = (mask >> 1) & 1;
            if ((a[i] - '0') == ((A ^ i) & 1)) continue;
            if ((b[i] - '0') == ((B ^ i) & 1)) continue;
            rep(c, T * 2 + 1) {
                if (cnt[c] == 0) continue;
                int c2 = c + A - B;
                cnt2[c2] = add(cnt2[c2], cnt[c]);
                dp2[c2] = add(dp2[c2], add(dp[c], mul(cnt[c], abs(c - T))));
            }
        }
        swap(dp, dp2);
        swap(cnt, cnt2);
    }
    cout << dp[T] << '\n';
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