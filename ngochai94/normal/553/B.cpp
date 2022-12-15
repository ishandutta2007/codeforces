#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, lis[55], dp[55], ans[55], k;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    dp[1] = 1;
    dp[2] = 2;
    FOR (i, 3, 52) dp[i] = dp[i - 1] + dp[i - 2];
    FOR (i, 1, n) ans[i] = i;
    int i = 1;
    while (i < n) {
        // cout << i << ' ' << k << endl;
        if (k > dp[n - i]) {
            swap (ans[i], ans[i + 1]);
            k -= dp[n - i];
            i += 2;
        } else {
            i++;
        }
    }
    FOR (i, 1, n) cout << ans[i] << ' ';
}