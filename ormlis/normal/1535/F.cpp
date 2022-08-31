#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int LG = 20;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    range(i, n) cin >> s[i];
    vector<vector<int>> groups;
    {
        vector<string> s2(n);
        range(i, n) {
            s2[i] = s[i];
            sort(all(s2[i]));
        }
        vector<int> ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return s2[i] < s2[j];
        });
        for (auto &i : ord) {
            if (groups.empty() || s2[groups.back().back()] != s2[i]) {
                groups.emplace_back();
            }
            groups.back().push_back(i);
        }
    }
    int m = s[0].size();
    ll ans = 0;
    int was = 0;
    for(auto &g : groups) {
        sort(all(g), [&] (const int &i, const int &j) {
            return s[i] < s[j];
        });
        int sz = g.size();
        vector<string> ss(sz);
        range(i, sz) {
            ss[i] = s[g[i]];
        }
        vector<string> rs(sz);
        range(i, sz) {
            rs[i] = ss[i];
            reverse(all(rs[i]));
        }
        vector<int> ord2(sz);
        iota(all(ord2), 0);
        sort(all(ord2), [&] (const int &i, const int &j) {
            return rs[i] < rs[j];
        });
        vector<int> pos(sz);
        range(i, sz) pos[ord2[i]] = i;
        int lg = 1;
        while((1 << lg) <= sz) lg++;
        vector<vector<int>> bup(sz, vector<int> (lg, -2));
        for(int i = 1; i < sz; ++i) {
            int a = ord2[i];
            int b = ord2[i - 1];
            while(rs[a][bup[i][0]] == rs[b][bup[i][0]]) {
                bup[i][0]++;
            }
            for(int j = 1; j < lg; ++j) {
                int x = 1 << j;
                if (i - x < -1) break;
                bup[i][j] = min(bup[i][j - 1], bup[i - (int)(1 << (j - 1))][j - 1]);
            }
        }
        auto get = [&] (int i, int x) {
            for(int j = lg - 1; j >= 0; --j) {
                if (bup[i][j] >= x) {
                    i -= (1 << j);
                }
            }
            return i;
        };
        vector<vector<int>> to(m, vector<int> (sz));
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < sz; ++j) {
                to[i][j] = to[i][j - 1];
                if (to[i - 1][j] != to[i - 1][j - 1]) {
                    to[i][j]++;
                    continue;
                }
                if (ss[j][i - 1] != ss[j - 1][i - 1]) {
                    to[i][j]++;
                }
            }
        }
        vector<int> nxt(sz);
        fenwick f;
        f.build(sz);
        ll cur = 0;
        range(i, m) {
            for(int j = 0, e = 0; j < sz; j = e) {
                while(e < sz && to[i][e] == to[i][j]) e++;
                // [j, e)
                for(int x = e - 1; x >= j; --x) {
                    if (nxt[x] == i) {
                        nxt[x]++;
                        while(nxt[x] < m && ss[x][nxt[x]] >= ss[x][nxt[x] - 1]) nxt[x]++;
                        int r = pos[x];
                        int need = m - nxt[x];
                        int l = get(r, need);
                        cur += f.get(l, r);
                    }
                    f.upd(pos[x], 1);
                }
                for(int x = j; x < e; ++x) {
                    f.upd(pos[x], -1);
                }
            }
        }
        ans += 1ll * was * sz * 1337;
        was += sz;
        ans += 1ll * sz * (sz - 1);
        ans -= cur;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}