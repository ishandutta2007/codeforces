#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, m, u, v, val, ini[200005], cur, from[200005], to[200005];
long long segl[1000006], segr[1000006];
int lvl[200005], id[200005];
vector<long long> adj[200005];
long long cache[1000006];


void dfs(int node) {
    from[node] = ++cur;
    id[cur] = node;
    for (int nex: adj[node]) if (!lvl[nex]) {
        lvl[nex] = 3 - lvl[node];
        dfs(nex);
    }
    to[node] = cur;
}

void iniSeg(int node, int ll, int rr) {
    segl[node] = ll;
    segr[node] = rr;
    if (ll != rr) {
        int mid = (ll + rr) / 2;
        iniSeg(node * 2, ll, mid);
        iniSeg(node * 2 + 1, mid + 1, rr);
    }
}

void writeSeg(int node, int l, int r, int val) {
    if (segl[node] > r || segr[node] < l) return ;
    if (segl[node] >= l && segr[node] <= r) {
        cache[node] += val;
        return;
    }
    writeSeg(node * 2, l, r, val);
    writeSeg(node * 2 + 1, l, r, val);
}

long long readSeg(int node, int x) {
    if (segl[node] > x || segr[node] < x) return 0;
    if (segl[node] == segr[node]) {
        int idd = id[x];
        if (lvl[idd] == 1) ini[idd] += cache[node];
        else ini[idd] -= cache[node];
        cache[node] = 0;
        return ini[idd];
    }
    cache[node * 2] += cache[node];
    cache[node * 2 + 1] += cache[node];
    cache[node] = 0;
    return readSeg(node * 2, x) + readSeg(node * 2 + 1, x);
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    FOR (i, 1, n) cin >> ini[i];
    REP (i, n - 1) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lvl[1] = 1;
    dfs(1);
    iniSeg(1, 1, to[1]);
    while (m--) {
        int typ;
        cin >> typ >> u;
        if (typ == 1) {
            cin >> val;
            if (lvl[u] == 2) val = -val;
            writeSeg(1, from[u], to[u], val);
        }
        else {
            cout << readSeg(1, from[u]) << endl;
        }
    }
}