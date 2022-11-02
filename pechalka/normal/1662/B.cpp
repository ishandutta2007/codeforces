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
const int maxN = 1e6 + 20;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

void solve() {
    int n = 3;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    int A = 26;
    vvi cnt(n, vi(A, 0));
    rep(i, n) {
        for (auto &x : a[i]) cnt[i][x - 'A']++;
    }
    vvi to(n);
    int res = 0;
    int L = 0;
    rep(i, n) L = max(L, (int) a[i].size());
    rep(x, A) {
        while (res < L) {
            int mx = 0;
            int mx2 = 1;
            if (cnt[1][x] > cnt[0][x]) swap(mx, mx2);
            if (cnt[2][x] > cnt[mx][x]) {
                mx2 = mx;
                mx = 2;
            } else if (cnt[2][x] > cnt[mx2][x]) {
                mx2 = 2;
            }
            if (cnt[mx2][x] == 0) break;
            to[3 ^ mx ^ mx2].push_back(x);
            cnt[mx][x]--;
            cnt[mx2][x]--;
            res++;
        }
    }
    vector<pair<int, int>> ans;
    vvi to2(n);
    rep(i, n) {
        rep(j, A) {
            rep(_, cnt[i][j]) {
                if (to[i].empty()) {
                    to2[i].push_back(j);
                } else {
                    ans.emplace_back(to[i].back(), j);
                    to[i].pop_back();
                }
            }
        }
        while(!to[i].empty()) {
            ans.emplace_back(to[i].back(), to[i].back());
            to[i].pop_back();
        }
    }
    while (true) {
        int mx = 0;
        int mx2 = 1;
        if (to2[1].size() > to2[0].size()) swap(mx, mx2);
        if (to2[2].size() > to2[mx].size()) {
            mx2 = mx;
            mx = 2;
        } else if (to2[2].size() > to2[mx2].size()) {
            mx2 = 2;
        }
        if (to2[mx].empty()) break;
        if (to2[mx2].empty()) {
            ans.emplace_back(to2[mx].back(), to2[mx].back());
            to2[mx].pop_back();
            continue;
        }
        ans.emplace_back(to2[mx].back(), to2[mx2].back());
        to2[mx].pop_back();
        to2[mx2].pop_back();
    }
    cout << ans.size() << '\n';
    for(auto &[x, y] : ans) cout << char('A' + x) << char('A' + y) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}