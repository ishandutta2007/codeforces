//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 500 * 1000 + 10;
vector<pii> hist;
int par[maxn],
    col[maxn],
    frm[maxn],
    too[maxn],
    eord[maxn],
    wei[maxn];
bool badcol[maxn];
bool bad;
LL n, m, k;

bool ecmp(int i, int j) {
    return col[frm[i]] == col[frm[j]] ? col[too[i]] < col[too[j]] : col[frm[i]] < col[frm[j]];
}

pii root(int u) {
    if (par[u] < 0)
        return MP(u, 0);
    pii p = root(par[u]);
    p.R ^= wei[u];
    return p;
}

void merge(int u, int v) {
    bad = false;
    pii ur = root(u);
    pii vr = root(v);
    if (ur.L == vr.L) {
        bad = ur.R ^ vr.R ^ 1;
        return;
    }
    if (par[ur.L] > par[vr.L])
        swap(ur, vr);
    hist.PB(MP(vr.L, par[vr.L]));
    par[ur.L] += par[vr.L];
    par[vr.L] = ur.L;
    wei[vr.L] = ur.R ^ vr.R ^ 1;
}

void checkpoint() {
    hist.PB(MP(-1, -1));
}

void rollback() {
    while (hist.back().L != -1) {
        int u = hist.back().L,
            p = hist.back().R;
        par[par[u]] -= p;
        par[u] = p;
        hist.pop_back();
    }
    hist.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(par, -1, sizeof par);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> col[i], col[i]--;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        if (col[fi] > col[se])
            swap(fi, se);
        frm[i] = fi;
        too[i] = se;
        if (col[fi] == col[se]) {
            merge(fi, se);
            if (bad)
                badcol[col[fi]] = true;
        }
    }
    iota(eord, eord + m, 0);
    sort(eord, eord + m, ecmp);
    LL tmp = count(badcol, badcol + k, false);
    LL ans = tmp * (tmp - 1) / 2;
    int r;
    for (int l = 0; l < m; l = r) {
        int le = eord[l];
        r = l;
        while (r < m and col[frm[le]] == col[frm[eord[r]]] and col[too[le]] == col[too[eord[r]]]) {
            r++;
        }
        if (col[frm[le]] == col[too[le]] or badcol[col[frm[le]]] or badcol[col[too[le]]])
            continue;
        int i;
        checkpoint();
        for (i = l; i < r; i++) {
            int e = eord[i];
            merge(frm[e], too[e]);
            if (bad) {
                ans--;
                break;
            }
        }
        rollback();
    }
    cout << ans << '\n';
	return 0;
}