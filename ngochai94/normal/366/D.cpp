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

int n, m, a[3333], b[3333], l[3333], r[3333], ans, vst[3333];
vector<int> adj[3333];
queue<int> q;

bool connected(int lef, int rig) {
    FOR (i, 1, n) adj[i].clear();
    REP (i, m) {
        // BUG(l[i]);
        if (l[i] <= lef && r[i] >= rig) {
            adj[a[i]].pb(b[i]);
            adj[b[i]].pb(a[i]);
            // BUG(i);
        }
    }
    reset(vst, 0);
    vst[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nex: adj[cur]) if (!vst[nex]) {
            vst[nex] = 1;
            q.push(nex);
        }
    }
    if (vst[n]) return true;
    else return false;
}

int solve(int lef) {
    int high = 1000006;
    int low = lef;
    while (low < high) {
        int chs = (low + high) / 2;
        if (connected(lef, chs)) low = chs + 1;
        else high = chs;
    }
    // cout << lef << ' ' << low << endl;
    return low - lef;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, m) {
        cin >> a[i] >> b[i] >> l[i] >> r[i];
    }
    REP (i, m) {
        ans = max(ans, solve(l[i]));
    }
    if (ans) cout << ans;
    else cout << "Nice work, Dima!";
}