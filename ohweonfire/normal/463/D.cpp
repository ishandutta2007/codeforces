#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std; 
int a[10][1005], b[10][1005], n, k, dp[1005]; 
int main() 
{
    scanf("%d%d", &n, &k); 
    int tmp ; 
    for(int i = 1; i <= k; i++) 
        for(int j = 1; j<= n; j++) {
            scanf("%d", &tmp); a[i][j] = tmp; b[i][tmp] = j; 
        }
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        dp[i] = 1; 
        for(int j = 1; j < i ; j++) {
            bool flag = false; 
            for(int t = 2; t <= k; t++)
                if(b[t][a[1][i]] < b[t][a[1][j]]) flag = true; 
            if(!flag)
				dp[i] = max(dp[j]+1, dp[i]); 
        }
        ans = max(ans, dp[i]); 
    }
    printf("%d\n", ans); 
    return 0; 
}