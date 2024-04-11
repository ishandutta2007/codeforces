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

struct Data {
    ll mp, ms;
    ll sm;
    ll ans;

    Data(ll x = 0)
        : mp(max(0ll, x))
        , ms(max(0ll, x))
        , sm(x)
        , ans(max(0ll, x))
    {
    }
};

Data mrg(Data l, Data r) {
    Data res;
    res.sm = l.sm + r.sm;
    res.mp = max(l.mp, l.sm + r.mp);
    res.ms = max(r.ms, l.ms + r.sm);
    res.ans = max(max(l.ans, r.ans), l.ms + r.mp);
    return res;
}

const int MX = 300 * 1000 + 7;
int p[MX], w[MX];
Data d[MX];

ll a[MX];

int getp(int v) {
    if (p[v] == -1) {
        return v;
    }
    p[v] = getp(p[v]);
    return p[v];
}

void join(int u, int v) {
    u = getp(u);
    v = getp(v);
    assert(u != v);
/*    if (w[u] < w[v]) {
        swap(u, v);
    } */
    w[u] += w[v];
    p[v] = u;
    d[u] = mrg(d[u], d[v]);
}

ll D[MX];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n;
    ll A;
    cin >> n >> A;
    ll ans = 0;
    vector<pair<ll, int> > go;

    for (int i = 0; i < n; i++) {
        cin >> D[i];
        cin >> a[i];
        a[i] = A - a[i];
        d[i] = Data(a[i]);
        p[i] = -1;
        ans = max(ans, a[i]);
        if (i > 0) {
            ll gap = (D[i] - D[i - 1]) * (D[i] - D[i - 1]);
            go.emplace_back(gap, i);
        }
    }

    sort(go.begin(), go.end());
    for (const auto& [val, pos] : go) {
        join(pos - 1, pos);
        int v = getp(pos);
        ans = max(ans, d[v].ans - val);
    }

    cout << ans << "\n";
    return 0;
}