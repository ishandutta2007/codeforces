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
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    vvi g(n * 2);
    rep(_, n * 2) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = 0;
    vi u(n * 2);
    rep(i, n) {
        if (u[i]) continue;
        int v = i;
        vi cur;
        while (!u[v]) {
            cur.push_back(v);
            u[v] = 1;
            int d = -1;
            for (auto &t : g[v]) {
                if (u[t]) continue;
                d = t;
                break;
            }
            if (d != -1) v = d;
        }
        int sz = (int) cur.size();
        {
            assert(cur.size() >= 4);
            int l = cur[0];
            int r = cur[0];
            int L = cur[1] - n;
            int R = cur[1] - n;
            for (int j = 0; j < (int) cur.size(); j += 2) {
                l = min(l, cur[j]);
                r = max(r, cur[j]);
                L = min(L, cur[j + 1] - n);
                R = max(R, cur[j + 1] - n);
            }
            ans += 1ll * (sz / 2) * (l + 1) * (n - r) * (L + 1) * (n - R);
        }
        for (int ls = 0; ls < sz; ++ls) {
            int l = cur[(ls + 1) % sz];
            int r = cur[(ls + 1) % sz];
            int L = cur[(ls + 2) % sz];
            int R = cur[(ls + 2) % sz];
            if (ls % 2 == 0) {
                swap(l, L);
                swap(r, R);
            }
            for (int rs = ls + 3; rs <= ls + sz; ++rs) {
                if (rs % 2 == 0) {
                    L = min(L, cur[(rs - 1) % sz]);
                    R = max(R, cur[(rs - 1) % sz]);
                } else {
                    l = min(l, cur[(rs - 1) % sz]);
                    r = max(r, cur[(rs - 1) % sz]);
                }
                int l1 = -1;
                int r1 = n;
                int L1 = n - 1;
                int R1 = 2 * n;
                {
                    int val = cur[ls % sz];
                    if (ls % 2) {
                        if (val < L) {
                            L1 = max(L1, val);
                        } else if (val > R) {
                            R1 = min(R1, val);
                        } else {
                            break;
                        }
                    } else {
                        if (val < l) {
                            l1 = max(l1, val);
                        } else if (val > r) {
                            r1 = min(r1, val);
                        } else {
                            break;
                        }
                    }
                }
                {
                    int val = cur[rs % sz];
                    if (rs % 2) {
                        if (val < L) {
                            L1 = max(L1, val);
                        } else if (val > R) {
                            R1 = min(R1, val);
                        } else {
                            continue;
                        }
                    } else {
                        if (val < l) {
                            l1 = max(l1, val);
                        } else if (val > r) {
                            r1 = min(r1, val);
                        } else {
                            continue;
                        }
                    }
                }
                ans += 1ll * ((rs - ls - 1) / 2) * (l - l1) * (r1 - r) * (L - L1) * (R1 - R);
            }
        }
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}