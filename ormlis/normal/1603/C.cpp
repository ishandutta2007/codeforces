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
const int maxN = 1e5 + 100;
const int LG = 30;


const int md = 998244353; //1e9 + 7, 1e9 + 9

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
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}


void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    int ans = 0;
    vector<pair<int, int>> dp;
    for (int i = n - 1; i >= 0; --i) {
        int cur = 1;
        while(!dp.empty() && dp.back().first >= a[i]) {
            cur = add(cur, dp.back().second);
            dp.pop_back();
        }
        vector<pair<int, int>> nxtdp;
        for(auto &[x, y] : dp) {
            int cnt = (a[i] + x - 1) / x;
            int last = a[i] / cnt;
            if (!nxtdp.empty() && nxtdp.back().first == last) {
                nxtdp.back().second = add(nxtdp.back().second, y);
            } else {
                nxtdp.emplace_back(last, y);
            }
            sum = add(sum, mul(y, cnt - 1));
        }
        ans = add(ans, sum);
        nxtdp.emplace_back(a[i], cur);
        swap(dp, nxtdp);
    }
    cout << ans << '\n';
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