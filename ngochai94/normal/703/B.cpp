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

long long n, k, lis[100005], val, ans, tot, cit;
int city[100005];

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    FOR (i, 1, n)
    {
        cin >> lis[i];
        tot += lis[i];
    }
    //FOR (i, 1, n - 1) ans += lis[i] * lis[i + 1];
    //ans += lis[1] * lis[n];
    //BUG(ans);
    while (k--)
    {
        cin >> val;
        tot -= lis[val];
        cit += lis[val];
        city[val] = 1;
    }
    long long tmp = 0;
    FOR (i, 1, n) if (city[i])
    {
        ans += lis[i] * tot;
        tmp += lis[i] * (cit - lis[i]);
    }
    //BUG(ans);
    FOR (i, 1, n - 1) if (!city[i] && !city[i + 1]) ans += lis[i] * lis[i + 1];
    //BUG(ans);
    //BUG(!city[n]);
    if (!city[1] && !city[n]) ans += lis[1] * lis[n];
    cout << ans + tmp / 2;
}