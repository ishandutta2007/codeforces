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
const int maxN = 1e6 + 30;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> pref(n);
    vector<ll> suf(n);
    vector<int> l(n, -1), r(n, n);
    {
        vector<int> stk;
        rep(i, n) {
            while (!stk.empty() && h[stk.back()] >= h[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) l[i] = stk.back();
            stk.push_back(i);
        }
    }
    {
        vector<int> stk;
        repr(i, n) {
            while (!stk.empty() && h[stk.back()] >= h[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) r[i] = stk.back();
            stk.push_back(i);
        }
    }
    rep(i, n) {
        int x = i;
        if (i > 1) pref[i] = pref[i - 1];
        while (x != -1) {
            pref[i] = max(pref[i], 1ll * (i - l[x]) * h[x]);
            x = l[x];
        }
    }
    repr(i, n) {
        int x = i;
        if (i + 1 < n) suf[i] = suf[i + 1];
        while (x != n) {
            suf[i] = max(suf[i], 1ll * (r[x] - i) * h[x]);
            x = r[x];
        }
    }
    ll ans = *max_element(all(pref));
    for (int i = 0; i + 1 < n; ++i) ans = max(ans, pref[i] + suf[i + 1]);
    rep(mid, n) {
        int L = l[mid];
        int R = r[mid];
        if (L == -1 || R == n) continue;
        vector<int> pathL;
        int x = L;
        while (x != -1) {
            pathL.push_back(x);
            x = l[x];
        }
        vector<int> pathR;
        x = R;
        while (x != n) {
            pathR.push_back(x);
            x = r[x];
        }
        {
            int j = (int) pathL.size();
            ll add = 0;
            rep(i, (int) pathR.size()) {
                int rr = pathR[i];
                int r2 = r[rr];
                ll hL = h[mid] - h[rr];
                while (j > 0 && h[pathL[j - 1]] <= hL) {
                    j--;
                    x = pathL[j];
                    add = max(add, 1ll * (R - 1 - l[x]) * h[x]);
                }
                ll val = h[rr] * (r2 - 1 - L);
                ll cur = add;
                if (j > 0) {
                    x = pathL[j - 1];
                    cur = max(cur, 1ll * (R - 1 - l[x]) * hL);
                }
                ans = max(ans, val + cur);
            }
        }
        {
            int j = (int) pathR.size();
            ll add = 0;
            rep(i, (int) pathL.size()) {
                int lb = pathL[i];
                int l2 = l[lb];
                ll hR = h[mid] - h[lb];
                while (j > 0 && h[pathR[j - 1]] <= hR) {
                    j--;
                    x = pathR[j];
                    add = max(add, 1ll * (r[x] - L - 1) * h[x]);
                }
                ll val = h[lb] * (R - 1 - l2);
                ll cur = add;
                if (j > 0) {
                    x = pathR[j - 1];
                    cur = max(cur, 1ll * (r[x] - L - 1) * hR);
                }
                ans = max(ans, val + cur);
            }
        }
        {
            int i = 0;
            int j = 0;
            ll add = 1ll * (R - 1 - L) * h[mid];
            while (i < pathL.size() || j < pathR.size()) {
                ll res = add;
                int cL, cR;
                if (i == (int) pathL.size()) cL = -1;
                else cL = pathL[i];
                if (j == (int) pathR.size()) cR = n;
                else cR = pathR[j];
                if (j != (int) pathR.size() &&
                    (i == (int) pathL.size() || h[cL] < h[cR])) {
                    res += h[cR] * ((L - cL) + (r[cR] - R));
                    j++;
                } else {
                    res += h[cL] * ((L - l[cL]) + (cR - R));
                    i++;
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}