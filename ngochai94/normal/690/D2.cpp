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

long long n, c;

long long expo(long long a, long long b)
{
    long long ret = 1;
    FORD (i, 25, 0)
    {
        ret *= ret;
        ret %= mod;
        if ((1 << i) & b)
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
    cin >> n >> c;
    long long ans = 0, cur = 1;
    FOR (i, 1, n)
    {
        cur *= c + i - 1;
        cur %= mod;
        cur *= expo(i, mod - 2);
        cur %= mod;
        ans += cur;
        ans %= mod;
    }
    cout << ans;
}