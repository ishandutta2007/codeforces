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

long long s, ans[200005], n, b[200005], c[200005];
long long hasBit[32];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> b[i];
    REP (i, n) cin >> c[i];
    REP (i, n) if (b[i] > c[i])
    {
        cout << -1;
        return 0;
    }
    REP (i, n) s += b[i] + c[i];
    if (s % (n + n))
    {
        cout << -1;
        return 0;
    }
    s /= n + n;
    REP (i, n)
    {
        long long tmp = b[i] + c[i] - s;
        if (tmp % n)
        {
            cout << -1;
            return 0;
        }
        ans[i] = tmp / n;
    }
    REP (i, n) REP (j, 32) if ((1ll << j) & ans[i]) hasBit[j]++;
    REP (i, n)
    {
        long long tmpb = 0, tmpc = 0;
        long long jj = 1;
        REP (j, 32)
        {
            if (jj & ans[i])
            {
                tmpb += hasBit[j] * jj;
                tmpc += n * jj;
            }
            else tmpc += hasBit[j] * jj;
            jj *= 2;
        }
        if (b[i] != tmpb || c[i] != tmpc)
        {
            cout << -1;
            return 0;
        }
    }
    REP (i, n) cout << ans[i] << ' ';
}