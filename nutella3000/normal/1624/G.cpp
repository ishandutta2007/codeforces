#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = (1 << 19);

int n, m;
vector<pair<pii, int>> ed;
bool ban[N];

bool min_t() {
    vector<int> par(n);
    iota(all(par), 0);

    function<int(int)> get = [&](int v) { return par[v] == v ? v : par[v] = get(par[v]); };
    auto merge = [&](int v1, int v2) { v1 = get(v1), v2 = get(v2), par[v1] = v2; };

    int cnt = n;
    for (int i = 0; i < m; ++i) {
        if (ban[i]) continue;
        int v1 = get(ed[i].fi.fi), v2 = get(ed[i].fi.se);
        if (v1 != v2) --cnt, merge(v1, v2);
    }
    return cnt == 1;
}

void run() {
    ed.clear();
    cin >> n >> m;
    fill(ban, ban + m, 0);
    for (int i = 0; i < m; ++i) {
        int v1, v2, c; cin >> v1 >> v2 >> c; --v1, --v2;
        ed.pb(mp(v1, v2), c);
    }
    int res = 0;
    for (int it = 30; it >= 0; --it) {
        vector<int> nb;
        for (int i = 0; i < m; ++i) {
            if (!ban[i] && (ed[i].se >> it & 1)) {
                nb.pb(i), ban[i] = true;
            }
        }
        if (!min_t()) {
            for (int i : nb) {
                ban[i] = false;
            }
            res += (1 << it);
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}