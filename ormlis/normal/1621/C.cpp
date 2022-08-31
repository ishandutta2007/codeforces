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
const int maxN = 6e6 + 100;
const int LG = 20;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "! 1" << endl;
        return;
    }
    vi p(n, -1);
    auto ask = [&] (int i) {
        cout << "? " << i + 1 << endl;
        int x; cin >> x;
        if (x == 0) {
            exit(0);
        }
        return x - 1;
    };
    rep(i, n) {
        if (p[i] != -1) continue;
        vector<int> cyc;
        cyc.push_back(ask(i));
        int v = cyc.back();
        while(cyc.size() <= 1 || v != cyc.front()) {
            v = ask(i);
            cyc.push_back(v);
        }
        for(int j = 0; j + 1 < (int)cyc.size(); ++j) p[cyc[j]] = cyc[j + 1];
    }
    cout << "! ";
    rep(i, n) cout << p[i] + 1 << ' ';
    cout << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}