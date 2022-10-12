#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;


int n;
int cnt[N];

LL dp[N];
LL f(int x) {
    if (x > 100000) return 0;
    if (~dp[x]) return dp[x];
    
    return dp[x] = max( f(x+1), f(x+2) + 1LL * cnt[x] * x);
}

int main() {
    scanf ("%d", &n);
    for (int i=0; i<n; i++) {
        int a;
        scanf ("%d", &a);
        cnt[a]++;   
    }
    
    memset (dp, -1, sizeof dp);
    printf ("%I64d\n", f(1));
    
    return 0;
}