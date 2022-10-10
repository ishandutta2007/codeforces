#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 300 * 1000 + 7;

struct T {
    int t[4 * MX];
    ll sm[4 * MX];

    void ad(int v, int tl, int tr, int pos, int val, ll rval) {
        if (tl == tr) {
            t[v] += val;
            sm[v] += rval;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                ad(v + v, tl, tm, pos, val, rval);
            } else {
                ad(v + v + 1, tm + 1, tr, pos, val, rval);
            }
            t[v] = t[v + v] + t[v + v + 1];
            sm[v] = sm[v + v] + sm[v + v + 1];
        }
    }

    int kth(int v, int tl, int tr, int l, int r, int k) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1;
            if (t[v + v] >= k) {
                return kth(v + v, tl, tm, l, r, k);
            } else {
                return kth(v + v + 1, tm + 1, tr, l, r, k - t[v + v]);
            }
        }
    }

    ll gt(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) {
            return 0;
        } else if (tl >= l && tr <= r) {
            return sm[v];
        } else {
            int tm = (tl + tr) >> 1;
            return gt(v + v, tl, tm, l, r) + gt(v + v + 1, tm + 1, tr, l, r);
        }
    }
};

T lt, rt;

int a[MX], b[MX];

int orda[MX], ordb[MX], ordab[MX];
int porda[MX], pordab[MX];

const ll INF = 1e18;

int res[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        orda[i] = i;
        ordb[i] = i;
        ordab[i] = i;
    }
    sort(orda, orda + n, [&](int x, int y) {
        return a[x] < a[y];
    });
    sort(ordb, ordb + n, [&](int x, int y) {
        return b[x] < b[y];
    });
    sort(ordab, ordab + n, [&](int x, int y) {
        return b[x] - a[x] > b[y] - a[y];
    });

    for (int i = 0; i < n; i++) {
        porda[orda[i]] = i;
        pordab[ordab[i]] = i;
    }

    ll sb = 0;
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        rt.ad(1, 0, n, porda[i], 1, a[i]);
    }

    int ansx = -1, ansy = -1, ansz = -1;
    for (int i = 0; i <= n; i++) {
        int v = ordb[i];
        int has = 2 * i;
        int takel = 0, taker = 0;
        int sizel = i, sizer = n - sizel;
        if (has >= w) {
            takel = has - w;
        } else {
            taker = w - has;
        }
        bool fl = false;
        if (takel > sizel || taker > sizer) {
            fl = true;
        }
        if (!fl) {
            int lg = 0, rg = n + 1;
            while (rg - lg > 1) {
                int mg = (lg + rg) >> 1;
                if (takel + mg > sizel) {
                    rg = mg;
                    continue;
                }
                if (taker + mg > sizer) {
                    rg = mg;
                    continue;
                }
                int posl = ordab[lt.kth(1, 0, n, 0, n, takel + mg)];
                int posr = orda[rt.kth(1, 0, n, 0, n, taker + mg)];
                if (b[posl] - a[posl] >= a[posr]) {
                    lg = mg;
                } else {
                    rg = mg;
                }
            }

            ll cans = sb;
            if (lg + takel > 0) {
                int pos = lt.kth(1, 0, n, 0, n, lg + takel);
                cans -= lt.gt(1, 0, n, 0, pos);
            }
            if (rg + taker > 0) {
                int pos = rt.kth(1, 0, n, 0, n, lg + taker);
                cans += rt.gt(1, 0, n, 0, pos);
            }
            if (cans < ans) {
                ans = cans;
                ansx = i;
                ansy = lg + takel;
                ansz = lg + taker;
            }
            ans = min(ans, cans);
        }
        sb += b[v];
        lt.ad(1, 0, n, pordab[v], 1, b[v] - a[v]);
        rt.ad(1, 0, n, porda[v], -1, -a[v]);
    }

    cout << ans << "\n";

    vector<pair<int, int> > ga;
    for (int i = 0; i < ansx; i++) {
        int v = ordb[i];
        res[v] = 2;
        ga.emplace_back(b[v] - a[v], v);
    }
    sort(ga.rbegin(), ga.rend());
    for (int i = 0; i < ansy; i++) {
        res[ga[i].second] = 1;
    }
    vector<pair<int, int> > gb;
    for (int i = ansx; i < n; i++) {
        int v = ordb[i];
        gb.emplace_back(a[v], v);
    }
    sort(gb.begin(), gb.end());
    for (int i = 0; i < ansz; i++) {
        res[gb[i].second] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
    cout << "\n";
    return 0;
}