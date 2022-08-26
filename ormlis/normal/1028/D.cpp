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
    set<int> sell, buy;
    set<int> hz;
    int ans = 1;
    rep(_, n) {
        string s; cin >> s;
        int p; cin >> p;
        if (s == "ADD") {
            int mask = 3;
            if (!sell.empty() && (*sell.begin()) <= p) {
                mask ^= 1;
            }
            if (!buy.empty() && (*buy.rbegin()) >= p) {
                mask ^= 2;
            }
            if (mask == 0) {
                cout << "0\n";
                return;
            }
            if (mask == 3) {
                hz.insert(p);
            } else if (mask == 2) {
                sell.insert(p);
            } else if (mask == 1) {
                buy.insert(p);
            }
        } else if (s == "ACCEPT") {
            if (hz.count(p)) {
                hz.erase(p);
                ans = mul(ans, 2);
            } else if (sell.count(p)){
                if (*sell.begin() != p) {
                    cout << "0\n";
                    return;
                }
                sell.erase(p);
            } else if (buy.count(p)) {
                if (*buy.rbegin() != p) {
                    cout << "0\n";
                    return;
                }
                buy.erase(p);
            }
            for(auto &kek : hz) {
                if (kek < p) {
                    buy.insert(kek);
                } else {
                    sell.insert(kek);
                }
            }
            hz.clear();
        }
    }
    ans = mul(ans, (int)hz.size() + 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}