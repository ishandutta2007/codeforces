#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
using namespace __gnu_pbds;

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

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    vector<vector<ld>> p(n, vector<ld>(n));
    rep(i, n) {
        rep(j, n) {
            int x;
            cin >> x;
            p[i][j] = x;
            p[i][j] /= (ld) 100;
        }
    }
    vector<ld> E(n, 1);
    E[n - 1] = 0;
    vector<ld> curp(n, 1);
    vi us(n, 0);
    vi ord = {n - 1};
    for (int i = 1; i < n; ++i) {
        int x = ord[i - 1];
        us[x] = 1;
        int mn = -1;
        ld valmn = -1;
        rep(j, n) {
            if (us[j]) continue;
            E[j] += p[j][x] * curp[j] * E[x];
            curp[j] *= (ld) 1.0 - p[j][x];
            if (curp[j] == 1) continue;
            ld val = E[j] / ((ld) 1.0 - curp[j]);
            if (mn == -1 || valmn > val) {
                valmn = val;
                mn = j;
            }
        }
        if (mn == -1) break;
        ord.push_back(mn);
        E[mn] /= ((ld) 1.0 - curp[mn]);
    }
    cout << E[0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}