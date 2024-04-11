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

int m, val, dp[1111][11][11], par[1111][11][11];
string s;
vector<int> w, ans;

void out(int x, int y)
{
    cout << "YES" << endl;
    FORD (i, m, 1)
    {
        int tmp = par[i][x][y];
        ans.pb(y);
        x = y - x;
        y = tmp;
    }
    FORD (i, ans.size() - 1, 0) cout << ans[i] << ' ';
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> s >> m;
    FOR (i, 1, 10) if (s[i - 1] == '1') w.pb(i);
    dp[0][0][0] = 1;
    FOR (i, 1, m) FOR (j, 1, 10)
    {
        for (int k: w) FOR (kk, 0, 10) if (k >= j && dp[i - 1][k - j][kk] && k != kk)
        {
            dp[i][j][k] = 1;
            par[i][j][k] = kk;
            if (i == m)
            {
                out(j, k);
                return 0;
            }
            break;
        }
    }
    cout << "NO";
}