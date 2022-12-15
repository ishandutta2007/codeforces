#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, cnt[100005], u, v, ans[100005], par[100005], dp[26][100005];
vector<int> adj[100005];
queue<int> q;
bool flag = false;

void solve(int x) {
    for (int nex: adj[x]) if (!~par[nex]) {
        par[nex] = x;
        solve(nex);
        REP (i, 26) if (dp[i][nex]) dp[i][x]++;
    }
    REP (i, 26) if (dp[i][x] >= 2) {
        FORD (j, i - 1, 0) if (!dp[j][x]) {
            ans[x] = j;
            break;
        }
        if (ans[x] == -1) {
            flag = true;
            return;
        }
        break;
    }
    if (!~ans[x]) {
        FORD (j, 25, 0) if (!dp[j][x]) {
            ans[x] = j;
            break;
        }
    }
    if (!~ans[x]) {
        flag = true;
        return;
    }
    FOR (i, ans[x] + 1, 25) dp[i][x] = 0;
    dp[ans[x]][x] = 1;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n - 1) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        cnt[u]++;
        cnt[v]++;
    }
    FOR (i, 1, n) if (cnt[i] == 1) q.push(i);
    int root = 0;
    while (!q.empty()) {
        root = q.front();
        q.pop();
        for (int nex: adj[root]) {
            cnt[nex]--;
            if (cnt[nex] == 1) q.push(nex);
        }
    }
    reset(ans, -1);
    reset(par, -1);
    par[root] = 0;
    solve(root);
    if (flag) {
        cout << "Impossible!";
        return 0;
    }
    FOR (i, 1, n) cout << (char)('A' + ans[i]) << ' ';
}