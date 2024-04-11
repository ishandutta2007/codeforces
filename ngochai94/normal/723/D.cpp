#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, m, k, vst[55][55], isLake[5555], cur, tot, r, c;
int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
string grid[55];
queue<int> qr, qc;
set<int> s;
pair<int, int> p[5555];

bool onBorder(int r, int c)
{
    return !r || !c || r == n - 1 || c == m - 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    REP (i, n) cin >> grid[i];
    reset(vst, -1);
    //BUG(n);
    REP (i, n) REP (j, m) if (!~vst[i][j] && grid[i][j] == '.')
    {
        //cout << i << ' ' << j << endl;
        vst[i][j] = cur++;
        isLake[vst[i][j]] = 1;
        qr.push(i);
        qc.push(j);
        int cnt = 1;
        while (!qr.empty())
        {
            r = qr.front();
            c = qc.front();
            qr.pop();
            qc.pop();
            if (onBorder(r, c))
            {
                isLake[vst[r][c]] = 0;
            }
            REP (dd, 4)
            {
                int nr = r + dr[dd];
                int nc = c + dc[dd];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (!~vst[nr][nc] && grid[nr][nc] == '.')
                {
                    vst[nr][nc] = vst[i][j];
                    qr.push(nr);
                    qc.push(nc);
                    cnt++;
                }
            }
        }
        //BUG(cnt);
        //cout << vst[i][j] << ' ' << isLake[vst[i][j]] << endl;
        if (isLake[vst[i][j]]) p[tot++] = {cnt, vst[i][j]};
    }
    sort(p, p + tot);
    //BUG(k);
    REP (i, tot - k) s.insert(p[i].second);
    int res = 0;
    //for (int i: s) cout << i << endl;
    REP (i, n) REP (j, m) if (s.count(vst[i][j]))
    {
        grid[i][j] = '*';
        res++;
    }
    cout << res << endl;
    REP (i, n) cout << grid[i] << endl;
}