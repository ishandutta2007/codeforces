#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234567;

map<string, int> mmap;
int n, val[maxn];
bool change[maxn];
vector<int> G[maxn];
string op[maxn];

void init() {
    mmap["AND"] = 1;
    mmap["OR"] = 2;
    mmap["XOR"] = 3;
    mmap["NOT"] = 4;
    mmap["IN"] = 5;
}

void dfs1(int u) {
    for (int v : G[u]) dfs1(v);
    switch (mmap[op[u]]) {
        case 1:
            val[u] = val[G[u][0]] & val[G[u][1]];
            break;
        case 2:
            val[u] = val[G[u][0]] | val[G[u][1]];
            break;
        case 3:
            val[u] = val[G[u][0]] ^ val[G[u][1]];
            break;
        case 4:
            val[u] = !val[G[u][0]];
            break;
        default:
            return;
    }
}

void dfs2(int u) {
    if (!change[u]) return;
    if (op[u] == "IN") return;
    int now;
    switch (mmap[op[u]]) {
        case 1:
            now = (val[G[u][0]] ^ 1) & val[G[u][1]];
            if (now != val[u]) change[G[u][0]] = true;
            now = val[G[u][0]] & (val[G[u][1]] ^ 1);
            if (now != val[u]) change[G[u][1]] = true;
            break;
        case 2:
            now = (val[G[u][0]] ^ 1) | val[G[u][1]];
            if (now != val[u]) change[G[u][0]] = true;
            now = val[G[u][0]] | (val[G[u][1]] ^ 1);
            if (now != val[u]) change[G[u][1]] = true;
            break;
        case 3:
            change[G[u][0]] = change[G[u][1]] = true;
            break;
        default:
            change[G[u][0]] = true;
    }
    for (int v : G[u]) dfs2(v);
}

int main() {
    init();
    scanf("%d", &n);
    FOR(i, 1, n) {
        cin >> op[i];
        int u, v;
        if (op[i] == "NOT") {
            scanf("%d", &u);
            G[i].pb(u);
        } else if (op[i] == "IN") {
            scanf("%d", &u);
            val[i] = u;
        } else {
            scanf("%d%d", &u, &v);
            G[i].pb(u);
            G[i].pb(v);
        }
    }
    dfs1(1);
    change[1] = true;
    dfs2(1);
    FOR(i, 1, n) if (op[i] == "IN") printf("%d", val[1] ^ change[i]);
    puts("");
    return 0;
}