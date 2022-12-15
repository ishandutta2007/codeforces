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

long long x;
long long m, dp[1 << 19][111], cnt[11], unit[11], num;

void toCnt(int mask)
{
    num = 0;
    reset(cnt, 0);
    FORD (i, 9, 0) if (unit[i] > 0)
    {
        cnt[i] = mask / unit[i];
        num += cnt[i];
        mask %= unit[i];
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> x >> m;
    while (x)
    {
        cnt[x % 10]++;
        x /= 10;
    }
    int cur = 1;
    reset(unit, -1);
    REP (i, 10) if (cnt[i])
    {
        unit[i] = cur;
        cur = unit[i] * (1 + cnt[i]);
    }
    FOR (mask, 1, cur - 1)
    {
        toCnt(mask);
        if (num == 1)
        {
            FOR (i, 1, 10) if (cnt[i]) dp[mask][i % m] = 1;
        }
        else REP (i, 10) if (cnt[i])
        {
            int submask = mask - unit[i];
            REP (j, m) dp[mask][(i + j * 10) % m] += dp[submask][j];
        }
    }
    cout << dp[cur - 1][0];
}