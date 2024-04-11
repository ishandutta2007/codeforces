#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, c[1111], p[1111], a, b, m, vst[1111], ans;
pair<int, int> vis[1111], table[1111];

void solve()
{
    cin >> n;
    REP (i, n)
    {
        cin >> c[i] >> p[i];
        vis[i] = {-p[i], i};
    }
    sort(vis, vis + n);
    cin >> m;
    REP (i, m)
    {
        cin >> a;
        table[i] = {a, i};
    }
    sort(table, table + m);
    int cnt = 0;
    reset(vst, -1);
    REP (i, n)
    {
        a = -vis[i]._1;
        b = vis[i]._2;
        //BUG(a);
        REP (j, m) if (table[j]._1 >= c[b] && !~vst[table[j]._2])
        {
            vst[table[j]._2] = b;
            cnt++;
            ans += a;
            break;
        }
    }
    cout << cnt << ' ' << ans << endl;
    REP (i, m) if (~vst[i]) cout << vst[i] + 1 << ' ' << i + 1 << endl;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif LOCAL
    ios::sync_with_stdio(0);
    int ntest = 1;
    //cin >> t;
    while (ntest--)
    {
        solve();
    }
}