#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000003
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long c, w, h;
deque<long long> dp;

long long expo(long long a, long long b)
{
    long long ret = 1;
    FORD (i, 30, 0)
    {
        ret *= ret;
        ret %= mod;
        if ((1 << i ) & b)
        {
            ret *= a;
            ret %= mod;
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> c >> w >> h;
    dp.push_back(1);
    dp.pb(1);
    long long hw = expo(h, w + 1);
    FOR (i, 1, c)
    {
        if (i < w + 1) dp.pb(((h + 1) * dp.back()) % mod);
        else
        {
            long long tmp = (h + 1) * dp.back();
            tmp -= hw * dp.front();
            tmp = (tmp % mod + mod) % mod;
            dp.pop_front();
            dp.pb(tmp);
        }
        //BUG(dp.size());
    }
    cout << dp.back();
}