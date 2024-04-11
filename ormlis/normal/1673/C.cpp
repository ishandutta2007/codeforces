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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4 * 1e4 + 1;
const int maxP = 1000;
const int LG = 30;


const int md = 1e9 + 7; //998244353; //1e9 + 9;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int dp[maxN][maxP];
vector<int> pals;
int sz;

void precalc() {
    for (int i = 1; i <= 9; ++i) pals.push_back(i);
    for (int i = 1; i <= 9; ++i) pals.push_back(i * 10 + i);
    for (int i = 10; i <= 99; ++i) {
        pals.push_back(i * 10 + (i / 10));
    }
    for (int i = 10; i <= 99; ++i) {
        pals.push_back(i * 100 + (i % 10) * 10 + (i / 10));
    }
    for (int i = 100; i < 400; ++i) {
        pals.push_back(i * 100 + ((i / 10) % 10) * 10 + (i / 100));
    }
    assert(pals.size() < maxP);
    sz = pals.size();
    rep(i, sz) dp[0][i] = 1;
    for (int i = 1; i < maxN; ++i) {
        rep(j, sz) {
            int e = i - pals[j];
            if (e >= 0) dp[i][j] = add(dp[i][j], dp[e][j]);
            dp[i][j + 1] = add(dp[i][j + 1], dp[i][j]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n][sz] << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    precalc();
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}