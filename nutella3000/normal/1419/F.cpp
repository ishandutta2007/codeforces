#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back

const int inf = 2e9 + 2;
const int max_n = 1e3 + 3;

int n;
vector<pii> p;
map<int, map<int, int>> xs, ys;
vector<vector<pii>> pot;

vector<int> get_ps(int x, int y, map<int, map<int, int>>& a, bool in) {
    vector<int> res = {-1, -1};
    auto it = a[x].lower_bound(y);
    
    if (in) ++it;
    if (it != a[x].end()) res[1] = it->se;
    if (in) --it;

    if (it != a[x].begin()) {
        --it;
        res[0] = it->se;
    }
    return res;
}

vector<int> get_ps(pii p, bool in = false) {
    vector<int> b = get_ps(p.fi, p.se, xs, in), b1 = get_ps(p.se, p.fi, ys, in);
    b.insert(b.end(), b1.begin(), b1.end());
    b.erase(remove(all(b), -1), b.end());
    return b;
}

int dist(pii a, pii b) { return abs(a.fi - b.fi) + abs(a.se - b.se); }

vector<pii> gr[max_n];
int comp[max_n];

void dfs(int v, int c, int len) {
    if (comp[v]) return;
    comp[v] = c;
    for (pii to : gr[v])
        if (to.se <= len) dfs(to.fi, c, len);
}

bool can(int len) {
    fill(comp, comp + n, 0);
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (!comp[i]) dfs(i, ++c, len);
    if (c >= 5) return false;
    if (c == 1) return true;

    for (auto vs : pot) {
        vector<bool> used(c + 1);
        int potc = c;
        for (pii i : vs) {
            if (i.se > len) continue;
            if (!used[comp[i.fi]]) --potc;
            used[comp[i.fi]] = true;
        }
        if (potc == 0) return true;
    }
    return false;
}

void add_p(pii a) {
    vector<int> t1 = get_ps(a);
    vector<pii> t2(size(t1));
    transform(all(t1), t2.begin(), [&](int x) { return mp(x, dist(p[x], a)); });
    pot.emplace_back(t2);
}

void run() {
    cin >> n;
    p.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].fi >> p[i].se;
        xs[p[i].fi][p[i].se] = i;
        ys[p[i].se][p[i].fi] = i;
    }

    set<pii> used;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pii v1 = mp(p[i].fi, p[j].se), v2 = mp(p[j].fi, p[i].se);
            pii v3 = mp((p[i].fi + p[j].fi) / 2, (p[i].se + p[j].se) / 2);
            if (p[i].fi != p[j].fi && p[i].se != p[j].se) {
                if (!used.count(v1)) add_p(v1);
                if (!used.count(v2)) add_p(v2);
                used.emplace(v1), used.emplace(v2);
            }
            else {
                if (!used.count(v3)) add_p(v3);
                used.emplace(v3);
            }
        }
        vector<int> tos = get_ps(p[i], true);
        for (int j : tos)
            gr[i].emplace_back(j, dist(p[i], p[j]));
    }
    
    int l = -1, r = inf;

    while (r - l > 1) {
        fill(comp, comp + n, 0);
        int mid = (l + r) / 2;

        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << (r == inf ? -1 : r) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    run();
}