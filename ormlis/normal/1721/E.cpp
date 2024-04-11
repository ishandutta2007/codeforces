#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

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
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e6 + 10;


void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> go(n + 1, vi(26, 0));
    vi p(n + 1);
    for(int i = 1; i <= n; ++i) {
        int x = s[i - 1] - 'a';
        p[i] = go[i - 1][x];
        go[i - 1][x] = i;
        go[i] = go[p[i]];
    }
    int q; cin >> q;
    rep(_, q) {
        string t; cin >> t;
        int k = p[n];
        vi cur(t.size());
        rep(j, t.size()) {
            int x = t[j] - 'a';
            while(k > n && t[k - n] != t[j]) {
                k = cur[k - n - 1];
            }
            if (k >= n && t[k - n] == t[j]) {
                k++;
            } else {
                k = go[k][x];
            }
            cur[j] = k;
            cout << k << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}