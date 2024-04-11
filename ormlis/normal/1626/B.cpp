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
const int maxN = 2e5 + 5;
const int LG = 20;

const int mod = 1e9 + 7;

void solve() {
    string x; cin >> x;
    int n = x.size();
    vi a(n);
    rep(i, n) a[i] = x[i] - '0';
    bool can = false;
    for(int i = 1; i < n; ++i) {
        if (a[i] + a[i - 1] >= 10) {
            can = true;
        }
    }
    if (!can) {
        cout << a[0] + a[1];
        for(int i = 2; i < n; ++i) cout << a[i];
        cout << '\n';
    } else {
        for(int i = n - 2; i >= 0; --i) {
            if (a[i] + a[i + 1] < 10) continue;
            int val = a[i] + a[i + 1];
            int p = val / 10;
            int q = val % 10;
            a[i] = p;
            a[i + 1] = q;
            break;
        }
        rep(i, n) cout << a[i];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}