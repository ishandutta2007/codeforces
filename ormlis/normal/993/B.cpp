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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }

    rep(i, m) {
        cin >> b[i].first >> b[i].second;
        if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
    }

    vi kek;
    bool has = false;
    for(auto &[x, y] : a) {
        int xt = 0, yt = 0;
        for(auto &[x2, y2] : b) {
            if (x2 == x && y2 == y) continue;
            if (x == x2) {
                xt++;
                kek.push_back(x);
            } else if (x == y2) {
                xt++;
                kek.push_back(x);
            } else if (y == x2) {
                yt++;
                kek.push_back(y);
            } else if (y == y2) {
                yt++;
                kek.push_back(y);
            }
        }
        if (xt > 0 && yt > 0) has = true;
    }

    for(auto &[x, y] : b) {
        int xt = 0, yt = 0;
        for(auto &[x2, y2] : a) {
            if (x2 == x && y2 == y) continue;
            if (x == x2) {
                xt++;
                kek.push_back(x);
            } else if (x == y2) {
                xt++;
                kek.push_back(x);
            } else if (y == x2) {
                yt++;
                kek.push_back(y);
            } else if (y == y2) {
                yt++;
                kek.push_back(y);
            }
        }
        if (xt > 0 && yt > 0) has = true;
    }
    sort(all(kek));
    kek.resize(unique(all(kek)) - kek.begin());
    if (kek.size() == 1) {
        cout << kek[0] << '\n';
        return;
    }
    if (!has) {
        cout << "0\n";
    } else {
        cout << "-1\n";
    }

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