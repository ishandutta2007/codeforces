#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
const int maxN = 2e6 + 30;
const int LG = 20;

bool prime[maxN];
int pref[maxN];
ll spref[maxN];

void solve() {
    int n, x, y; cin >> n >> x >> y;
    rep(_, n) {
        int v; cin >> v;
        pref[v]++;
        spref[v] += v;
    }
    rep(i, maxN - 1) pref[i + 1] += pref[i];
    rep(i, maxN - 1) spref[i + 1] += spref[i];
    rep(i, maxN) prime[i] = true;
    ll ans = 1ll * n * x;
    for(int p = 2; p < maxN; ++p) {
        if (!prime[p]) continue;
        if (1ll * p * p < maxN) for(int j = p * p; j < maxN; j += p) prime[j] = false;
        ll cur = 0;
        int d = min(x / y, p - 1);
        for(int i = p; i < maxN; i += p) {
            cur += 1ll * (pref[i - d - 1] - pref[i - p]) * x;
            cur += 1ll * (1ll * (pref[i] - pref[i - d - 1]) * i - (spref[i] - spref[i - d - 1])) * y;
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}