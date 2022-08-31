#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db long double
#define mp make_pair
const int N = 27;
int n, m, a[N], sum[4096], cnt, onecnt;
bool dp[2][4096][N]; // 0 : tree; 1 : forest
int main() {
    scanf("%d", &n);
    L(i, 1, n) {
        scanf("%d", &a[i]);
        if(a[i] > 1) a[++cnt] = a[i];
    }
    if(cnt * 2 + 1 > n) return printf("NO\n"), 0;
    onecnt = n - cnt, n = cnt;
    sort(a + 1, a + n + 1);
    L(i, 1, n) sum[1 << (i - 1)] = 1;
    dp[0][0][1] = 1; L(i, 2, onecnt) dp[1][0][i] = 1;
    L(i, 1, (1 << n) - 1) {
        sum[i] = ((i & 1) + sum[i >> 1]);
        int t = log2(i), pp = i - (1 << t), ned = a[t + 1] - 1 - sum[pp];
        L(j, 0, ned) dp[0][i][ned] |= dp[1][pp][j];
        for(int d = 1, k = pp; d; d = k, k = ((k - 1) & pp)) L(j, 0, onecnt) L(d, 0, j) 
            dp[1][i][j] |= (dp[0][i ^ k][j - d] & (dp[0][k][d] | dp[1][k][d])); 
    }
    printf("%s\n", dp[0][(1 << n) - 1][onecnt] ? "YES" : "NO");
    return 0;
}