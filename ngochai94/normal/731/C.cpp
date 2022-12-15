#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, m, k, a, b, vst[200005], col[200005];
vector<int> adj[200005];
map<int, int> cnt;
queue<int> q;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    REP (i, n) cin >> col[i];
    while (m--)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 0;
    REP (i, n) if (!vst[i])
    {
        vst[i] = 1;
        int cur = 1;
        q.push(i);
        cnt.clear();
        cnt[col[i]] = 1;
        int save = 1;
        while (!q.empty())
        {
            a = q.front();
            q.pop();
            for (int nex: adj[a]) if (!vst[nex])
            {
                vst[nex] = 1;
                cur++;
                q.push(nex);
                cnt[col[nex]]++;
                save = max(save, cnt[col[nex]]);
            }
        }
        ans += cur - save;
    }
    cout << ans;
}