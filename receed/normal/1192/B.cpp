#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#ifdef ONPC
    #define getchar getchar_unlocked
#else
    #define getchar _getchar_nolock
#endif

using namespace std;
using ll = long long;
using ld = long double;

char mem[500 * 1000 * 1000];
int mpos;

void* operator new(size_t sz) {
    mpos += sz;
    return mem + mpos - sz;
}

void operator delete(void* ptr) {}
char c;
void ri(ll &x) {
    while (c < '0' || c > '9')
        c = getchar();
    x = 0;
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

const int N = 1 << 17, L = 18;
ll tr[L][N * 2], mod[L][N * 2], rd[N];
int tin[L][N], tout[L][N], ev[L][N];
vector<int> til[N];
multiset<ll> js[N], qs;
vector<pair<int, int>> g[N];
ll ew[N];
int dd[N], sz[N], ct[L][N], tt[L];

void push(int t, int v) {
    if (!mod[v])
        return;
    tr[t][v] += mod[t][v];
    if (v < N) {
        mod[t][v * 2] += mod[t][v];
        mod[t][v * 2 + 1] += mod[t][v];
    }
    mod[t][v] = 0;
}

void rel(int t, int v) {
    tr[t][v] = max(tr[t][v * 2], tr[t][v * 2 + 1]);
}

void add(int t, int cl, int cr, ll d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(t, v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[t][v] += d;
        push(t, v);
        return;
    }
    push(t, v);
    add(t, cl, cr, d, v * 2, l, (l + r) / 2);
    add(t, cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(t, v);
}

ll getmx(int t, int cl, int cr, int v=1, int l=0, int r=N) {
    push(t, v);
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[t][v];
    return max(getmx(t, cl, cr, v * 2, l, (l + r) / 2), getmx(t, cl, cr, v * 2 + 1, (l + r) / 2, r));
}


void csz(int v, int p) {
    sz[v] = 1;
    for (auto &pp : g[v])
        if (pp.first != p && !dd[pp.first]) {
            csz(pp.first, v);
            sz[v] += sz[pp.first];
        }
}

int fc(int v, int p, int fs) {
    int mv = -1;
    for (auto &pp : g[v]) {
        int u = pp.first;
        if (u != p && !dd[u] && (mv == -1 || sz[u] > sz[mv]))
            mv = u;
    }
    if (mv != -1 && sz[mv] * 2 > fs)
        return fc(mv, v, fs);
    return v;
}

void setc(int v, int p, int cc, int l) {
    ct[l][v] = cc;
    tin[l][v] = tt[l]++;
    tr[l][N + tin[l][v]] = rd[v];
    for (auto &pp : g[v])
        if (pp.first != p && !dd[pp.first]) {
            rd[pp.first] = rd[v] + ew[pp.second];
            ev[l][pp.second] = pp.first;
            setc(pp.first, v, cc, l);
        }
    tout[l][v] = tt[l];
}

void build(int v, int l) {
    csz(v, -1);
    int cc = fc(v, -1, sz[v]);
    rd[cc] = 0;
    setc(cc, -1, cc, l);
    dd[cc] = l + 1;
    for (auto &pp : g[cc])
        if (!dd[pp.first]) {
            til[cc].push_back(tin[l][pp.first]);
            build(pp.first, l + 1);
        }
    til[cc].push_back(tout[l][cc]);
}

ll get(int v) {
    if (js[v].empty())
        return 0;
    if (js[v].size() == 1)
        return *--js[v].end();
    return *--js[v].end() + *----js[v].end();
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, u, v, q;
    ll w;
    ri(n);
    ri(q);
    ri(w);
    rep(i, n - 1) {
        ri(u); ri(v); ri(ew[i]);
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    build(1, 0);
    rep(i, L)
        for (int j = N - 1; j > 0; j--)
            tr[i][j] = max(tr[i][j * 2], tr[i][j * 2 + 1]);
    for (int i = 1; i <= n; i++) {
        rep(j, (int) til[i].size() - 1)
            js[i].insert(getmx(dd[i] - 1, til[i][j], til[i][j + 1]));
        qs.insert(get(i));
    }
    ll last = 0, qd, qe;
    rep(j, q) {
        ri(qd); ri(qe);
        qd = (qd + last) % (n - 1);
        qe = (qe + last) % w;
        ll cd = qe - ew[qd];
        ew[qd] = qe;
        rep(i, L) {
            v = ev[i][qd];
            if (!v)
                break;
            int cc = ct[i][v];
            int pos = lower_bound(all(til[cc]), tin[i][v] + 1) - til[cc].begin() - 1;
            qs.erase(qs.find(get(cc)));
            js[cc].erase(js[cc].find(getmx(i, til[cc][pos], til[cc][pos + 1])));
            add(i, tin[i][v], tout[i][v], cd);
            js[cc].insert(getmx(i, til[cc][pos], til[cc][pos + 1]));
            qs.insert(get(cc));
        }
        last = *--qs.end();
        cout << last << '\n';
    }
}