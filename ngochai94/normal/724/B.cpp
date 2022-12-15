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

int n, m, lis[22][22];

bool checkRow(int x)
{
    REP (i, m) if (lis[x][i] != i + 1) return false;
    return true;
}

bool check()
{
    REP (i, n)
    {
        REP (j, m) if (lis[i][j] != j + 1)
        {
            //cout << i << ' ' <<
            int k = lis[i][j] - 1;
            swap(lis[i][j], lis[i][k]);
            bool tmp = checkRow(i);
            swap(lis[i][j], lis[i][k]);
            if (!tmp) return false;
        }
    }
    return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, n) REP (j, m) cin >> lis[i][j];
    if (check())
    {
        cout << "YES";
        return 0;
    }
    FOR (i, 0, m - 1) FOR (j, i + 1, m - 1)
    {
        REP (k, n)
        {
            swap (lis[k][i], lis[k][j]);

        }
        if (check())
            {
                cout << "YES";
                return 0;
            }
            REP (k, n) swap(lis[k][i], lis[k][j]);
    }
    cout << "NO";
}