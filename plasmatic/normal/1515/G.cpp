// ./g-phoenix-and-odometers.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

using pii = pair<int, int>;
using T = tuple<int, int, int>;
using Edge = tuple<int, int, int, int>;

const int MN = 2e5 + 10;
int N, M, Q;
vector<T> g[MN];

int cord = 0,
    ord[MN], low[MN];
bool instk[MN];
vector<int> stk;

int to[MN], compNo = 0;

void dfs(int c) {
    ord[c] = low[c] = ++cord;
    instk[c] = true;
    stk.push_back(c);

    for (auto [to, tow, idx] : g[c]) {
        if (!ord[to]) {
            dfs(to);
            low[c] = min(low[c], low[to]);
        }
        else if (instk[to])
            low[c] = min(low[c], ord[to]);
    }

    if (low[c] == ord[c]) {
        int no = compNo++, v = -1;
        do {
            v = stk.back(); stk.pop_back();
            instk[v] = false;
            to[v] = no;
        } while (v != c);
    }
}

vector<int> nodes[MN];
vector<Edge> edges[MN];
vector<T> tg[MN];
ll compGcd[MN], dep[MN];

void dfs(int c, int curComp) {
    for (auto [to, w, idx] : tg[c]) {
        if (dep[to] == -1) {
            dep[to] = dep[c]+w;
            dfs(to, curComp);
        }
        else
            compGcd[curComp] = gcd(compGcd[curComp], dep[c]-dep[to]+w);
    }
}

void pans(bool ok) {
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int a, b, l; cin >> a >> b >> l;
        g[a].emplace_back(b, l, i);
    }
    for (auto i = 1; i <= N; i++) {
        if (!ord[i]) {
            dfs(i);
        }
    }
    for (auto i = 1; i <= N; i++) {
        for (auto [tov, w, idx] : g[i])
            if (to[i] == to[tov])
                edges[to[i]].emplace_back(i, tov, w, idx);
        nodes[to[i]].push_back(i);
    }

    // solve for each SCC
    memset(dep, -1, sizeof dep);
    for (auto i = 0; i < compNo; i++) {
        for (auto [a, b, w, idx] : edges[i]) tg[a].emplace_back(b, w, idx);

        dep[nodes[i][0]] = 0;
        dfs(nodes[i][0], i);

        for (auto n : nodes[i]) {
            dep[n] = -1;
            tg[n].clear();
        }
    }

    cin >> Q;
    while (Q--) {
        int s, v, mod;
        cin >> s >> v >> mod;

        ll gg = compGcd[to[s]] % mod;
        if (gg < 0) gg += mod;
        ll gcdv = gcd(gg, mod), need = mod-v;
        pans(need % gcdv == 0);
    }

    return 0;
}