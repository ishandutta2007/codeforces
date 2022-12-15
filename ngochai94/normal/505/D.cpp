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

int n, m, u, v, ans, vst[100005], cntt[100005];
vector<int> from[100005], to[100005];
queue<int> q, qq;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        from[u].pb(v);
        to[v].pb(u);
        cntt[v]++;
    }
    ans = n;
    FOR (i, 1, n) if (!vst[i]) {
        q.push(i);
        vst[i] = 1;
        int cur = 0;
        while(!q.empty()) {
            u = q.front();
            if (!cntt[u]) qq.push(u);
            q.pop();
            cur++;
            for (int nex: from[u]) if (!vst[nex]) {
                vst[nex] = 1;
                q.push(nex);
            }
            for (int nex: to[u]) if (!vst[nex]) {
                vst[nex] = 1;
                q.push(nex);
            }
        }
        while (!qq.empty()) {
            u = qq.front();
            qq.pop();
            cur--;
            for (int nex: from[u]) {
                cntt[nex]--;
                if (!cntt[nex]) qq.push(nex);
            }
        }
        if (!cur) ans--;
    }
    cout << ans;
}