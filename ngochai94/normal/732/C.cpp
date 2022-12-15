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

long long a, b, c;

long long f(long long x, long long y, long long z)
{
    long long tot = max(x, max(y, z));
    return tot - x + tot - y + tot - z;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    long long ans = 6 + 3 * max(max(a, b), c);
    long long x = a, y = b, z = c;
    ans = min(ans, f(x, y, z));
    ans = min(ans, f(x - 1, y, z));
    ans = min(ans, f(x - 1, y - 1, z));
    ans = min(ans, f(x, y, z - 1));
    ans = min(ans, f(x - 1, y, z - 1));
    ans = min(ans, f(x, y - 1, z - 1));
    ans = min(ans, f(x - 1, y - 2, z - 1));
    cout << ans;
}