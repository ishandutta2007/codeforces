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

int n, lis[111], high;
char ans[11111][111];

bool check(int x)
{
    int tot = 0;
    REP (i, n)
    {
        if (i != high) tot += lis[i] - x;
    }
    return tot >= lis[high] - x;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    FOR (i, 1, n - 1) if (lis[i] > lis[high]) high = i;
    int tmp = lis[0];
    FOR (i, 1, n - 1) tmp = min(tmp, lis[i]);
    FORD (i, tmp, 0) if (check(i))
    {
        int match = 0;
        REP (j, n) match += lis[j] - i;
        match /= 2;
        cout << i << endl << match << endl;
        REP (j, match) REP (k, n) ans[j][k] = '0';
        int cur = 0;
        REP (j, n)
        {
            REP (k, lis[j] - i)
            {
                ans[cur][j] = '1';
                cur++;
                cur %= match;
            }
        }
        REP (j, match)
        {
            REP (k, n) cout << ans[j][k];
            cout << endl;
        }
        return 0;
    }
    cout << 0 << endl << 111 << endl;
    REP (i, 111)
    {
        REP (i, n) cout << 1;
        cout << endl;
    }
}