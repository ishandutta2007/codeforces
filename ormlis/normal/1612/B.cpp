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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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
const int maxN = 1e5;

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vi to1, to2, to3;
    for (int i = 1; i <= n; ++i) {
        if (i == a) {
            to1.push_back(i);
        } else if (i == b) {
            to2.push_back(i);
        } else {
            int ct = 0;
            if (i > a) ct++;
            if (i < b) ct++;
            if (ct == 2) {
                to3.push_back(i);
                continue;
            }
            if (ct == 0) {
                cout << "-1\n";
                return;
            }
            if (i > a) to1.push_back(i);
            else to2.push_back(i);
        }
    }
    if (to1.size() > n / 2 || to2.size() > n / 2) {
        cout << "-1\n";
        return;
    }
    for(auto &x : to3) {
        if (to1.size() < n / 2) to1.push_back(x);
        else to2.push_back(x);
    }
    for(auto &x : to1) cout << x << ' ';
    for(auto &x : to2) cout << x << ' ';
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