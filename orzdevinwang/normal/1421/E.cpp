#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db long double
#define mp make_pair
const int N = 2e5 + 7;
const ll INF = 1e18;
int n, m, a[N], cnta, cntb;
ll dp[N][3], fla, flb;
void Max(ll &x, ll y) { x = (x > y ? x : y); }
int main() {
    scanf("%d%d", &n, &a[1]), fla = a[1], flb = -a[1], cntb = 1;
    if(n == 1) return printf("%d\n", a[1]), 0;
    dp[1][0] = dp[1][1] = dp[1][2] = -INF;
    L(i, 2, n) {
        dp[i][0] = dp[i][1] = dp[i][2] = -INF;
        scanf("%d", &a[i]);
        if(i % 2 == 0) {
            Max(dp[i][cnta % 3], fla + a[i]), fla -= a[i], cnta++;
            Max(dp[i][(cntb + 1) % 3], flb - a[i]), flb += a[i]; 
        } 
        else {
            Max(dp[i][(cnta + 1) % 3], fla - a[i]), fla += a[i];
            Max(dp[i][cntb % 3], flb + a[i]), flb -= a[i], cntb++;
        }
        Max(dp[i][0], dp[i - 1][2] - a[i]);
        Max(dp[i][1], dp[i - 1][0] - a[i]);
        Max(dp[i][2], dp[i - 1][1] - a[i]);
        Max(dp[i][0], dp[i - 1][0] + a[i]);
        Max(dp[i][1], dp[i - 1][1] + a[i]);
        Max(dp[i][2], dp[i - 1][2] + a[i]);
    }
    printf("%lld\n", dp[n][(1 + 2 * n) % 3]);
    return 0;
}