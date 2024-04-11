// ./c-team-building.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using T = tuple<int, int, int, int, int>;
using pii = pair<int, int>;

const int MN = 5e5 + 1;
int N, M, K,
    C[MN];
vector<int> g[MN], team[MN];
map<pii, vector<pii>> between;
map<int, int> mpInTeam[MN];

struct {
    int r, rnk;
} dsu[MN*2];
vector<T> ch; // x, y, old dsu[y], old rnk[x], id
void init() { for (auto i = 0; i < MN*2; i++) dsu[i] = {i, 1}; }
int rt(int x) { return dsu[x].r == x ? x : rt(dsu[x].r); }
void unite(int x, int y, int id) {
    x = rt(x); y = rt(y);
    if (x == y) return;
    if (dsu[x].rnk < dsu[y].rnk) swap(x, y);
    ch.emplace_back(x, y, dsu[y].r, dsu[x].rnk, id);
    dsu[y].r = x;
    dsu[x].rnk += dsu[x].rnk == dsu[y].rnk;
}
void undo(int toid) {
    while (!ch.empty()) {
        auto &[x, y, dy, rx, id] = ch.back();
        if (id < toid) break;
        dsu[y].r = dy;
        dsu[x].rnk = rx;
        ch.pop_back();
    }
}

bool teamBad[MN];
set<int> adjTeam[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (auto i = 1; i <= N; i++) {
        cin >> C[i];
        team[C[i]].push_back(i);
    }
    for (auto i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        adjTeam[C[a]].insert(C[b]);
        adjTeam[C[b]].insert(C[a]);
        if (C[a] > C[b]) swap(a, b);
        between[{C[a], C[b]}].emplace_back(a, b);
    }

    init();
    int nonBad = 0;
    for (auto i = 1; i <= K; i++) {
        for (auto [a, b] : between[{i, i}]) {
            unite(a, b+N, 0);
            unite(a+N, b, 0);
        }
        for (auto x : team[i]) {
            teamBad[i] |= rt(x) == rt(x+N);
            mpInTeam[i][x] = rt(x);
            mpInTeam[i][x+N] = rt(x+N);
        }
        nonBad += !teamBad[i];
        undo(0);
    }

    init();
    ll ans = ll(nonBad)*(nonBad-1)/2;
    for (auto i = 1; i <= K; i++) {
        if (!teamBad[i]) {
            for (auto [a, b] : between[{i, i}]) {
                unite(a, b+N, 0);
                unite(a+N, b, 0);
            }
            for (auto t : adjTeam[i]) {
                if (!teamBad[t]) {
                    if (team[i].size() < team[t].size() || (team[i].size() == team[t].size() && i > t)) continue; // size[i]>=size[t] always

                    bool isBad = false;
                    int _a = i, _b = t; if (_a > _b) swap(_a, _b);
                    for (auto [a, b] : between[{_a, _b}]) {
                        if (C[a] != i) swap(a, b); // C[a] must be i

                        int b1 = mpInTeam[t][b], b2 = mpInTeam[t][b+N];
                        unite(a, b2, 1);
                        unite(a+N, b1, 1);
                        if (rt(a) == rt(a+N) || rt(b1) == rt(b2)) {
                            isBad = true;
                            break;
                        }
                    }
                    ans -= isBad;
                    undo(1);
                }
            }
            undo(0);
        }
    }

    cout << ans << '\n';

    return 0;
}