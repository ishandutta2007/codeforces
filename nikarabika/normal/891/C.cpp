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
int par[maxn],
    wei[maxn],
    frm[maxn],
    too[maxn],
    ans[maxn],
    n, m;
vector<pii> hist;
vector<int> wall, ord;
vector<pair<vector<int> *, int> > quers[maxn];

int root(int u) {
    return par[u] < 0 ? u : root(par[u]);
}

bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v)))
        return false;
    if (par[u] > par[v])
        swap(u, v);
    hist.PB(MP(v, par[v]));
    par[u] += par[v];
    par[v] = u;
    return true;
}

void checkpoint() {
    hist.PB(MP(-1, -1));
}

void rollback() {
    while (hist.back().L != -1) {
        int v = hist.back().L,
            old = hist.back().R;
        int u = par[v];
        par[u] -= old;
        par[v] = old;
        hist.pop_back();
    }
    hist.pop_back();
}

bool check(vector<int>::iterator ord, int n, bool undo) {
    if (undo) checkpoint();
    bool result = true;
    for (int i = 0; i < n; i++) {
        if (!merge(frm[ord[i]], too[ord[i]])) {
            result = false;
            if (undo)
                break;
        }
    }
    if (undo) rollback();
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(par, -1, sizeof par);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        frm[i] = fi;
        too[i] = se;
        wei[i] = th;
        wall.PB(th);
    }
    sort(all(wall));
    wall.resize(unique(all(wall)) - wall.begin());
    ord.resize(m);
    iota(ord.begin(), ord.end(), 0);
    sort(all(ord), [](int i, int j) -> bool { return wei[i] < wei[j]; });
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int qq;
        cin >> qq;
        vector<int> vec;
        while (qq--) {
            int x;
            cin >> x, x--;
            vec.PB(x);
        }
        sort(all(vec), [](int i, int j) -> bool { return wei[i] < wei[j]; });
        for (int l = 0, r = 0; l < sz(vec); l = r) {
            int id = lower_bound(all(wall), wei[vec[l]]) - wall.begin();
            vector<int> *inds = new vector<int>;
            while (r < sz(vec) and wei[vec[l]] == wei[vec[r]])
                inds->PB(vec[r++]);
            quers[id].PB(MP(inds, i));
        }
    }
    int ptr = 0;
    memset(ans, true, sizeof ans);
    for (int i = 0; i < sz(wall); i++) {
        for (auto req: quers[i])
            if (ans[req.R] and !check(req.L->begin(), req.L->size(), true))
                ans[req.R] = false;
        int nptr = ptr;
        while (nptr < m and wei[ord[nptr]] == wall[i])
            nptr++;
        check(ord.begin() + ptr, nptr - ptr, false);
        ptr = nptr;
    }
    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "YES\n" : "NO\n");
	return 0;
}