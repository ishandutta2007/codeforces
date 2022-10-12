#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n;
string s;

int dp[75][1 << 20];

int f(int x, int mask) {
    if (x == n) return 0;
    if (~dp[x][mask]) return dp[x][mask];
    
    long long ret = 0;
    
    int cur = 0;
    for (int i=x; i<n; i++) {
        cur <<= 1;
        if (s[i] == '1') cur++;
        
        if (cur > 20) break;
        if (cur == 0) continue;
        
        int nmask = (mask | (1 << cur-1));
        ret += f(i+1, nmask);
        if ( ((nmask+1) & -(nmask+1)) == nmask + 1 ) ret++;
    }   
    
    return dp[x][mask] = ret % MOD;
}

int main() {    
    cin >> n;
    cin >> s;
    
    memset(dp, -1, sizeof dp);
    
    long long ans = 0;
    for (int i=0; i<n; i++) ans += f(i, 0);
    
    printf("%lld\n", ans % MOD);
    return 0;
}