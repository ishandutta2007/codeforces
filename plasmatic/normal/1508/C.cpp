// ./c-complete-the-mst.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

struct DSU {
    vector<int> dsu;
    void init(int N) {
        dsu.resize(N + 1);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
    void merge(int x, int y) { // x -> y
        dsu[rt(x)] = rt(y); }
    bool same(int x, int y) { return rt(x) == rt(y); }
};
using T = tuple<int, int, int>;
const int MN = 2e5 + 1, LG = 18;
int N, M;
vector<int> g[MN];
vector<T> es;

int cid[MN], extEdgeCnt[MN];
bool vis[MN];
vector<vector<int>> comps;
vector<vector<pii>> compEds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int txor = 0;
    for (auto i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);

        es.push_back({c, a, b});

        txor ^= c;
    }

    set<int> can; 
    for (auto i = 1; i <= N; i++) can.insert(i);
    queue<int> q;
    for (auto i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = true; q.push(i); can.erase(i);
            comps.push_back(vector<int>());
            compEds.push_back(vector<pii>());
            int cno = comps.size();
            while (!q.empty()) {
                int c = q.front(); q.pop();
                comps.back().push_back(c);
                cid[c] = cno;

                vector<int> readd;
                for (auto to : g[c]) {
                    if (can.count(to)) {
                        readd.push_back(to);
                        can.erase(to);
                    }
                }

                vector<int> nxt;
                for (auto to : can) {
                    assert(!vis[to]);
                    compEds.back().emplace_back(c, to);
                    vis[to] = true;
                    nxt.push_back(to);
                    q.push(to);
                }

                for (auto x : readd) can.insert(x);
                for (auto x : nxt)
                    if (can.count(x))
                        can.erase(x);
            }
        }
    }

    for (auto i = 0; i < M; i++) {
        auto [_, a, b] = es[i];
        if (cid[a] == cid[b]) {
            extEdgeCnt[cid[a]]++;
        }
    }

    int compCnt = comps.size();
    bool compHasCycle = false;
    for (auto i = 1; i <= compCnt; i++) {
        ll nodesCnt = comps[i-1].size(), edgeCnt = nodesCnt*(nodesCnt-1)/2 - extEdgeCnt[i];
        if (edgeCnt >= nodesCnt)
            compHasCycle = true;
    }
    // printf("txor=%d compHasCycle=%d\n", txor, compHasCycle);

    // krooskal
    sort(es.begin(), es.end());
    if (compHasCycle) {
        ll ans = 0;
        DSU dsu; dsu.init(N);
        for (auto &comp : comps) {
            // printf("comp ");
            for (auto x : comp) {
                dsu.merge(comp.front(), x);
                // printf("%d ", x);
            }
            // printf("\n");
        }
        for (auto [w, a, b] : es){
            if (!dsu.same(a, b)) {
                dsu.merge(a, b);
                ans += w;
            }
        }
        cout << ans << '\n';
    }
    else {
        vector<pii> extraEds;
        for (auto &compEd : compEds)
            extraEds.insert(extraEds.end(), compEd.begin(), compEd.end());

        ll ans = LLINF;
        DSU dsu;
        for (auto [sa, sb] : extraEds) {
            ll cans = 0;
            dsu.init(N);
            for (auto [a, b] : extraEds) {
                if (sa != a || sb != b)
                    dsu.merge(a, b);
            }
            for (auto [w, a, b] : es) {
                if (w > txor) {
                    if (!dsu.same(sa, sb)) {
                        dsu.merge(sa, sb);
                        cans += txor;
                    }
                }
                if (!dsu.same(a, b)) {
                    dsu.merge(a, b);
                    cans += w;
                }
            }

            ans = min(ans, cans);
        }

        cout << ans << '\n';
    }

    return 0;
}