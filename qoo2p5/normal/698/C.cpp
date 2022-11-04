#include <bits/stdc++.h>

using namespace std;

#define ll long long
const double EPS = 1e-9;
const int INF = 1e9;
const ll LINF = 1e18;

const int N = 20;

int n, k;
double p[N];
double ans[N];
double dp[1 << N];

int main() {
    scanf("%d%d", &n, &k);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
        if (p[i] == 0) {
            zeros++;
        }
    }
    
    k = min(k, n - zeros);
    
    dp[0] = 1;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        double sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cnt++;
                sum += p[i];
            }
        }
        
        if (sum + EPS < 1) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    dp[mask | (1 << i)] += dp[mask] * p[i] / (1 - sum);
                }
            }
        }
        
        if (cnt == k) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    ans[i] += dp[mask];
                }
            }
            sum += dp[mask];
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%.15f ", ans[i]);
    }
    printf("\n");
    
    return 0;
}