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
const int maxN = 2e5;
const int LG = 30;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vi ord1(n);
    vi ord2(n);
    iota(all(ord1), 0);
    iota(all(ord2), 0);
    sort(all(ord1), [&] (const int &i, const int &j) { return a[i] < a[j]; });
    sort(all(ord2), [&] (const int &i, const int &j) { return b[i] < b[j]; });
    vi sm1(n + 1), sm2(n + 1);
    sm1[n] = sm2[n] = n;
    rep(i, n) a[ord1[i]] = i;
    rep(i, n) b[ord2[i]] = i;
    for(int i = n - 1; i >= 0; --i) {
        sm1[i] = min(sm1[i + 1], b[ord1[i]]);
        sm2[i] = min(sm2[i + 1], a[ord2[i]]);
    }
    int L = n - 1;
    int R = n - 1;
    rep(_, n * 2) {
        L = sm2[R];
        R = sm1[L];
    }
    rep(i, n) {
        if (a[i] >= L) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << '\n';
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