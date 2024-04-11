#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
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

bool check(vector<int> a, vector<int> b) {
    rep(_, 2) {
        for (int i = 0; i + (int) a.size() <= (int) b.size(); ++i) {
            bool ok = true;
            rep(j, (int) a.size()) {
                ok &= (a[j] == b[i + j]);
            }
            rep(j, i) ok &= (b[j] == 1);
            for (int j = (int) a.size() + i; j < (int) b.size(); ++j) {
                ok &= (b[j] == 1);
            }
            if (ok) return true;
        }
        reverse(all(a));
    }
    return false;
}

void solve() {
    ll x, y; cin >> x >> y;
    if (x == y) {
        cout << "YES\n";
        return;
    }
    vector<int> a, b;
    {
        ll t = x;
        while(t) {
            a.push_back(t % 2);
            t /= 2;
        }
    }
    {
        ll t = y;
        while(t) {
            b.push_back(t % 2);
            t /= 2;
        }
    }
    reverse(all(a));
    reverse(all(b));
    bool can = false;
    if (a.back() == 0) {
        a.push_back(1);
        can = check(a, b);
        a.pop_back();
        while(a.back() == 0) a.pop_back();
    }
    if (check(a, b)) can = true;
    if (can) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    rep(_, t) {
        solve();
    }
    return 0;
}