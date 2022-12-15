#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, vst[111][111], ans, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string grid[111];
queue<int> qr, qc;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, n) cin >> grid[i];
    REP (i, n) REP (j, m) if (grid[i][j] == 'B' && !vst[i][j])
    {
        qr.push(i);
        qc.push(j);
        ans++;
        vst[i][j] = 1;
        while (!qr.empty())
        {
            int r = qr.front(); qr.pop();
            int c = qc.front(); qc.pop();
            REP (dd, 4)
            {
                int nr = r + dx[dd];
                int nc = c + dy[dd];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 'B' && !vst[nr][nc])
                {
                    qr.push(nr);
                    qc.push(nc);
                    vst[nr][nc] = 1;
                }
            }
        }
    }
    cout << ans;
}