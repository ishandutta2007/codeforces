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


void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> cur;
    rep(i, n) cur.emplace_back(i, i);
    vvi ans(n, vi(n, -1));
    int c = 1;
    while(cur.size() > 1) {
        rep(a, (int)cur.size()) {
            rep(b, a) {
                for(int v1 = cur[a].first; v1 <= cur[a].second; ++v1) {
                    for(int v2 = cur[b].first; v2 <= cur[b].second; ++v2) {
                        ans[v2][v1] = c;
                    }
                }
            }
        }
        int cnt = ((int)cur.size() + k - 1) / k;
        vector<pair<int, int>> nxt;
        rep(a, (int)cur.size()) {
            if (a % k == 0) {
                nxt.push_back(cur[a]);
                continue;
            }
            nxt.back().second = cur[a].second;
        }
        swap(nxt, cur);
        c++;
    }
    cout << c - 1 << '\n';
    rep(i, n) {
        for(int j = i + 1; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
    }
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