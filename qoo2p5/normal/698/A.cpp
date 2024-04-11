#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int INF = 1e9;
const ll LINF = 1e18;

const int N = 1000;

int n;
int a[N];
int dp[N][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        fill(dp[i], dp[i] + 3, INF);
        
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        if (a[i] & 1) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if (a[i] & 2) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    
    printf("%d\n", *min_element(dp[n], dp[n] + 3));
    
    return 0;
}