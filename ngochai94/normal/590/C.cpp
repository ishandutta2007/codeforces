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

int n, m, ans[1111][1111], vst[1111][1111], res;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
string grid[1111];
queue<int> qr, qc;

void solve(char a, char b, char cc)
{
    reset(vst, -1);
    int resb = mod;
    int resc = mod;
    REP (i, n) REP (j, m) if (grid[i][j] == a)
    {
        qr.push(i);
        qc.push(j);
        vst[i][j] = 0;
        ans[i][j] += vst[i][j];
    }
    while (!qr.empty())
    {
        int r = qr.front();
        int c = qc.front();
        //cout << r << ' ' << c << endl;
        qr.pop();
        qc.pop();
        REP (dd, 4)
        {
            int nr = r + dr[dd];
            int nc = c + dc[dd];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != '#' && !~vst[nr][nc])
            {
                vst[nr][nc] = 1 + vst[r][c];
                ans[nr][nc] += vst[nr][nc];
                if (grid[nr][nc] == b) resb = min(resb, 1 + vst[r][c]);
                if (grid[nr][nc] == cc) resc = min(resc, 1 + vst[r][c]);
                qr.push(nr);
                qc.push(nc);
            }
        }
    }
    //cout << a << ' ' << b << ' ' << cc << ' ' << resb << ' ' << resc << endl;
    if (resb != mod && resc != mod) res = min(res, resb + resc);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    res = mod;
    REP (i, n) cin >> grid[i];
    solve('1', '2', '3');
    solve('2', '1', '3');
    solve('3', '2', '1');
    REP (i, n) REP (j, m) if (ans[i][j]) res = min(res, ans[i][j]);
    if (res == mod) cout << -1;
    else cout << res - 2;
}