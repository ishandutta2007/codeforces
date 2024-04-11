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

long long sieve[3000], dp[5000006];
vector<int> prime;
int t, a, b;

int main(){
    ios::sync_with_stdio(0);
    FOR (i, 2, 2999) if (!sieve[i]) {
        prime.pb(i);
        for (int j = i * 2; j < 3000; j += i) sieve[j] = 1;
    }
    FOR (i, 2, 5000000) {
        bool flag = false;
        for (int j: prime) if (i % j == 0) {
            dp[i]=  dp[i / j] + 1;
            flag = true;
            break;
        }
        if (!flag) {
            dp[i] = 1;
        }
    }
    // FOR (i, 2, 10) cout << i << ' ' << dp[i] << endl;
    FOR (i, 3, 5000000) dp[i] += dp[i - 1];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", dp[a] - dp[b]);
    }
}