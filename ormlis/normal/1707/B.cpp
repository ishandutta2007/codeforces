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
const int LG = 20;
const int maxN = 2e5;

void solve() {
    int n; cin >> n;
    int cnt0 = 0;
    vi a;
    rep(i, n) {
        int x; cin >> x;
        if (x == 0) {
            cnt0++;
        } else {
            a.push_back(x);
        }
    }
    reverse(all(a));
    while(true) {
        if (a.size() == 1) {
            cout << a[0] << '\n';
            return;
        }
        if (a.empty()) {
            cout << "0\n";
            return;
        }
        rep(i, (int)a.size() - 1) {
            a[i] -= a[i + 1];
        }
        if (cnt0) {
            cnt0--;
        } else {
            a.pop_back();
        }
        sort(rall(a));
        while(!a.empty() && a.back() == 0) {
            a.pop_back();
            cnt0++;
        }
    }
    assert(0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}