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
const int maxN = 5e4 + 5;
const int LG = 19;

const int md = 1000000007;
int seed, vmax;

int rnd() {
    int ret = seed;
    seed = (1ll * seed * 7 + 13) % md;
    return ret;
}

int pw(int a, int b, int mod) {
    int r = 1;
    for(; b; b >>= 1, a = (1ll * a * a) % mod) if (b & 1) r = (1ll * r * a) % mod;
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m >> seed >> vmax;
    vi a(n);
    rep(i, n) a[i] = (rnd() % vmax) + 1;
    set<ar<ll, 3>> segs;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && a[j] == a[i]) j++;
        segs.insert({i + 1, j, a[i]});
    }

    rep(_, m) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) swap(l, r);
        int x, y;
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % vmax) + 1;
        }
        if (op == 4) y = (rnd() % vmax) + 1;
        vector<ar<ll, 3>> have;
        {
            ar<ll, 3> tmp = {l, -1, -1};
            auto it = segs.lower_bound(tmp);
            if (it != segs.begin()) it--;
            while (it != segs.end()) {
                auto cur = (*it);
                if (cur[0] > r + 1) break;
                if (cur[1] + 1 < l) {
                    it++;
                    continue;
                }
                auto it2 = it;
                it++;
                segs.erase(it2);
                have.push_back(cur);
            }
        }
        if (op == 1) {
            for (auto &[l1, r1, val] : have) {
                if (r1 < l || l1 > r) {
                    segs.insert({l1, r1, val});
                    continue;
                }
                if (l1 < l) segs.insert({l1, l - 1, val});
                if (r1 > r) segs.insert({r + 1, r1, val});
                segs.insert({max(1ll * l, l1), min(1ll * r, r1), val + x});
            }
        } else if (op == 2) {
            for (auto &[l1, r1, val] : have) {
                if (val == x) {
                    l1 = min((int) l1, l);
                    r1 = max((int) r1, r);
                }
            }
            for (auto &[l1, r1, val] : have) {
                if (r1 < l || l1 > r) {
                    segs.insert({l1, r1, val});
                    continue;
                }
                if (l1 < l) segs.insert({l1, l - 1, val});
                if (r1 > r) segs.insert({r + 1, r1, val});
            }
            segs.insert({l, r, x});
        } else if (op == 3) {
            for (auto &[l1, r1, val] : have) segs.insert({l1, r1, val});
            sort(all(have), [&](const ar<ll, 3> &i, const ar<ll, 3> &j) {
                return i[2] < j[2];
            });
            for(auto [l1, r1, val] : have) {
                l1 = max(l1, 1ll * l);
                r1 = min(r1, 1ll * r);
                if (l1 > r1) continue;
                x -= r1 - l1 + 1;
                if (x <= 0) {
                    cout << val << '\n';
                    break;
                }
            }
        } else {
            int ans = 0;
            for (auto &[l1, r1, val] : have) segs.insert({l1, r1, val});
            for(auto [l1, r1, val] : have) {
                l1 = max(l1, 1ll * l);
                r1 = min(r1, 1ll * r);
                if (l1 > r1) continue;
                int cnt = r1 - l1 + 1;
                ans += (1ll * cnt * pw(val % y, x, y)) % y;
                ans %= y;
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
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