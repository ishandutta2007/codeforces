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

int n, c, lis[2][500005], l[2], ans[1000006];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%d %d", &n, &c);
    //cin >> l[0];
    scanf("%d", &l[0]);
    REP (i, l[0]) scanf("%d", &lis[0][i]);
    int need = 0;
    FOR (i, 1, n - 1)
    {
        int i0 = (i + 1) % 2;
        int i1 = 1 - i0;
        int diff = -1;
        //cin >> l[i1];
        //REP (j, l[i1]) cin >> lis[i1][j];
        scanf("%d", &l[i1]);
        REP (j, l[i1]) scanf("%d", &lis[i1][j]);
        REP (j, min(l[0], l[1])) if (lis[0][j] != lis[1][j])
        {
            diff = j;
            break;
        }
        if (diff == -1)
        {
            if (l[i1] < l[i0])
            {
                cout << -1;
                return 0;
            }
            continue;
        }
        //BUG(diff);
        int c0 = lis[i0][diff];
        int c1 = lis[i1][diff];
        if (c0 < c1)
        {
            ans[0]++;
            ans[c - c1 + 1]--;
            ans[c - c0 + 1]++;
        }
        else
        {
            ans[c - c0 + 1]++;
            ans[c - c1 + 1]--;
        }
        need++;
    }
    int cur = 0;
    //REP (i, c) cout << ans[i] << ' ';cout << endl;
    REP (i, c)
    {
        //BUG(cur);
        cur += ans[i];
        if (cur == need)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}