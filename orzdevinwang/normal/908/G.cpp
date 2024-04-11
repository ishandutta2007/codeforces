#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 755;
const int mod = 1e9 + 7;
int len, js, a[N], ans, cnt;
int dp[N][N], g[N];
int dfs(int now, int gs, bool flag) {
    if(now == len + 1) return (gs == 0);
    if(gs < 0) return 0;
    if(flag && dp[now][gs] != -1) return dp[now][gs];
    int maxn = flag ? 9 : a[now], res = 0;
    L(i, 0, maxn) (res += dfs(now + 1, gs - (i >= js), flag | (i != maxn))) %= mod;
    if(flag) dp[now][gs] = res;
    return res;
}
void solve() { // >= x
    L(i, 0, len) fill(dp[i], dp[i] + len + 1, -1);
    L(i, 1, len) (ans += 1ll * dfs(1, i, 0) * g[i] % mod) %= mod;   
}
char s[N];
int main() {
    scanf("%s", s + 1), len = strlen(s + 1);
    L(i, 1, len) a[i] = s[i] - '0';
    int now = g[1] = 1;
    L(i, 2, len) now = 1ll * now * 10 % mod, g[i] = (g[i - 1] + now) % mod;
    L(i, 1, 9) js = i, solve();
    printf("%d\n", ans);
    return 0;
}