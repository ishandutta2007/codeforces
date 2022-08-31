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
const int maxN = 2e5 + 10;


template<class T, class Fun = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;

    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<T>(n));
        rep(i, n) sp[0][i] = a[i];
        rep(j, lg - 1) {
            rep(i, n) {
                if (i + (1 << (j + 1)) > n) break;
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    T get(int l, int r) {
        int k = __lg(r - l);
        return f(sp[k][l], sp[k][r - (1 << k)]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vi IT(n);
    iota(all(IT), 0);
    SparseTable sp(IT, [&](const int &i, const int &j) {
        return p[i] > p[j] ? i : j;
    });
    vi a(n);
    int k = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] == 0) k++;
    }
    bool ok = true;
    vector<pair<int, int>> segs;
    function<int(int, int, int)> solve = [&](int l, int r, int mx) {
        if (l >= r) return 0;
        int j = sp.get(l, r);
        if (a[j] != 0) {
            if (a[j] > mx) ok = false;
            mx = a[j] - 1;
        }
        int mn = max(solve(l, j, mx), solve(j + 1, r, mx));
        if (a[j] == 0) {
            if (mn > mx) {
                ok = false;
            } else {
                segs.push_back({mn, mx});
            }
            return mn;
        } else {
            return a[j] + 1;
        }
    };
    solve(0, n, 1e6 + 20);
    vi s(k - 1);
    rep(i, k - 1) cin >> s[i];
    sort(all(s));
    vpi result;
    rep(_, 1) {
        if (!ok) continue;
        set<pair<int, int>> cur;
        vi ord(k);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return segs[i].first < segs[j].first;
        });
        int j = 0;
        rep(i, k - 1) {
            int x = s[i];
            while (j < k && segs[ord[j]].first <= x) {
                cur.insert({segs[ord[j]].second, ord[j]});
                j++;
            }
            while (!cur.empty() && cur.begin()->first < x) {
                int e = cur.begin()->second;
                result.push_back(segs[e]);
                cur.erase(cur.begin());
            }
            if (cur.empty()) {
                ok = false;
                break;
            }
            int e = cur.begin()->second;
            cur.erase(cur.begin());
        }
        if (!ok) continue;
        if (!cur.empty()) {
            int e = cur.begin()->second;
            result.push_back(segs[e]);
        }
        cur.clear();
        sort(all(ord), [&](const int &i, const int &j) {
            return segs[i].second > segs[j].second;
        });
        j = 0;
        repr(i, k - 1) {
            int x = s[i];
            while (j < k && segs[ord[j]].second >= x) {
                cur.insert({segs[ord[j]].first, ord[j]});
                j++;
            }
            while (!cur.empty() && cur.rbegin()->first > x) {
                int e = cur.rbegin()->second;
                result.push_back(segs[e]);
                cur.erase(prev(cur.end()));
            }
            if (cur.empty()) {
                ok = false;
                break;
            }
            int e = cur.rbegin()->second;
            cur.erase(prev(cur.end()));
        }
        if (!cur.empty()) {
            int e = cur.begin()->second;
            result.push_back(segs[e]);
        }
    }
    int L = 1e6 + 5;
    int R = -1;
    if (ok) {
        for(auto [l, r] : result) L = min(L, l);
        for(auto [l, r] : result) R = max(R, r);
    }
    rep(i, q) {
        int x;
        cin >> x;
        if (L <= x && x <= R) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}