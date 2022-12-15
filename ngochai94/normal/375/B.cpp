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
#define MAXN 30005

int n, toLeft[5555][5555], m, tmp[5555];
string grid[5555];

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, n) cin >> grid[i];
    reset(toLeft, 0);
    REP (i, n) {
        if (grid[i][0] == '1') toLeft[i][0] = 1;
        FOR (j, 1, m - 1) if (grid[i][j] == '1') toLeft[i][j] = (~toLeft[i][j - 1]) ? toLeft[i][j - 1] + 1 : 1;
    }
    int ans = 0;
    REP (j, m) {
        REP (i, n) tmp[i] = toLeft[i][j];
        sort(tmp, tmp + n);
        REP (i, n) ans = max(ans, tmp[i] * (n - i));
    }
    cout << ans;
}