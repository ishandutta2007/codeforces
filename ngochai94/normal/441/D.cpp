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
#define offset 1100

int n, lis[3333], grp[3333], ini, tar;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n)
    {
        cin >> lis[i];
    }
    cin >> tar;
    FOR (i, 1, n) if (!grp[i])
    {
        grp[i] = i;
        int tmp = lis[i];
        while (tmp != i)
        {
            grp[tmp] = i;
            tmp = lis[tmp];
        }
        ini++;
    }
    tar = n - tar;
    if (ini == tar)
    {
        cout << 0;
        return 0;
    }
    if (ini > tar)
    {
        cout << ini - tar << endl;
        REP (i, ini - tar)
        {
            cout << 1 << ' ';
            FOR (j, 2, n) if (grp[j] != 1)
            {
                cout << j << ' ';
                FOR (k, j + 1, n) if (grp[k] == grp[j]) grp[k] = 1;
                grp[j] = 1;
                break;
            }
        }
        return 0;
    }
    cout << tar - ini << endl;
    REP (i, tar - ini)
    {
        FOR (j, 1, n) if (lis[j] != j)
        {
            int ans = lis[j];
            int tmp = lis[j];
            while (tmp != j)
            {
                ans = min(ans, tmp);
                tmp = lis[tmp];
            }
            cout << j << ' ' << ans << ' ';
            swap (lis[j], lis[ans]);
            break;
        }
    }
}