#include <cstdio>
#include <vector>
#include <map>

using namespace std;

const long long mod = 998244353;

void TestCase() {
    int n; scanf("%d", &n);
    vector<vector<long long>>C(n + 1, vector<long long>(n + 1));
    C[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    
    map<int, int>m;
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        m[x]++;
    }
    
    vector<vector<long long>>dp(n + 1, vector<long long>(n / 2 + 1));
    dp[0][0] = 1;
    int sum = 0;
    
    for(auto it = m.rbegin(); it != m.rend(); it++) {
        int cnt = it -> second;
        for(int even = 0; even <= sum && even <= n / 2; even++) {
            
            if(even == n / 2) {
                int odd = sum - even;
                int freeOdd = n / 2 - odd;
                if(freeOdd >= cnt) {
                    dp[sum + cnt][even] += dp[sum][even] * C[freeOdd][cnt];
                    dp[sum + cnt][even] %= mod;
                }
            } else {
                int odd = sum - even;
                int freeOdd = max(0, even - odd - 1);
                if(freeOdd >= cnt) {
                    dp[sum + cnt][even] += dp[sum][even] * C[freeOdd][cnt];
                    dp[sum + cnt][even] %= mod;
                }
                if(freeOdd >= cnt - 1 && even + 1 <= n / 2) {
                    dp[sum + cnt][even + 1] += dp[sum][even] * C[freeOdd][cnt - 1];
                    dp[sum + cnt][even + 1] %= mod;
                }
            }
            
            
        }
        
        
        sum += cnt;
    }
    
//     for(int i = 0; i <= n; i++) {
//         for(int j = 0; j <= n / 2; j++) {
//             printf("%lld ", dp[i][j]);
//         }
//         printf("\n");
//     }
    
    printf("%lld\n", dp[n][n / 2]);
}

int main() {
    int t; scanf("%d", &t);
    while(t--)
        TestCase();
    return 0;
}