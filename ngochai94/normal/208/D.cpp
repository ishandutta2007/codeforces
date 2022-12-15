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

long long n, cost[5], lis[55], cur, ans[5];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    REP (i, 5) cin >> cost[i];
    REP (i, n)
    {
        cur += lis[i];
        //BUG(cur);
        while (cur >= cost[0])
        {
            //BUG(cost[0]);
            FORD (j, 4, 0) if (cur >= cost[j])
            {
                //cur = cost[j];
                ans[j] += cur / cost[j];
                cur %= cost[j];
                break;
            }
        }
    }
    REP (i, 5) cout << ans[i] << ' ';
    cout << endl << cur;
}