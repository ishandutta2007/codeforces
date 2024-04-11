#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long
#define db double
#define mp make_pair
const int N = (1 << 24);
int n, m, dp[N + 5]; ll sum;
char s[5];
int main() {
    int hh = N - 1;
    scanf("%d", &n);
    L(i, 1, n) {
        scanf("%s", s);
        dp[hh ^ ((1 << (s[0] - 'a')) | (1 << (s[1] - 'a')) | (1 << (s[2] - 'a')))]++;
    }
    L(i, 0, 23) L(j, 0, hh) if(!(j & (1 << i))) dp[j] += dp[j ^ (1 << i)];
    L(i, 0, hh) dp[i] = n - dp[i], sum ^= 1ll * dp[i] * dp[i];
    printf("%lld\n", sum);
    return 0;
}