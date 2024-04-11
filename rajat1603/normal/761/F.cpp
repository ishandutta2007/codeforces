#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int K = 3e5 + 5;
int n , m , k;
char str[N][N];
long long cnt[N][N][27];
int a[K] , b[K] , c[K] , d[K];
char e[K];
long long ans;
void update(int x1 , int y1 , int x2 , int y2 , int val){
    ++cnt[x1][y1][val];
    --cnt[x1][y2 + 1][val];
    --cnt[x2 + 1][y1][val];
    ++cnt[x2 + 1][y2 + 1][val];
}
long long get(int x1 , int y1 , int x2 , int y2 , int val){
    long long res = 0;
    res += cnt[x2][y2][val] - cnt[x2][y2][0];
    res -= cnt[x1 - 1][y2][val] - cnt[x1 - 1][y2][0];
    res -= cnt[x2][y1 - 1][val] - cnt[x2][y1 - 1][0];
    res += cnt[x1 - 1][y1 - 1][val] - cnt[x1 - 1][y1 - 1][0];
    return res;
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str[i] + 1);
    }
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d %d %d %d %c" , a + i , b + i , c + i , d + i , e + i);
        update(a[i] , b[i] , c[i] , d[i] , e[i] - 'a' + 1);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            for(int k = 1 ; k <= 26 ; ++k){
                cnt[i][j][k] += cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k];
                cnt[i][j][0] += cnt[i][j][k];
            }    
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cnt[i][j][str[i][j] - 'a' + 1] += k - cnt[i][j][0];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            int sum1 = 0;
            int cnt1 = 0;
            int sum2 = 0;
            int cnt2 = 0;
            for(int k = 1 ; k <= 26 ; ++k){
                cnt2 += cnt[i][j][k];
                sum2 += cnt[i][j][k] * k;
            }
            for(int k = 1 ; k <= 26 ; ++k){
                int cnt = ::cnt[i][j][k];
                cnt2 -= cnt;
                sum2 -= cnt * k;
                cnt1 += cnt;
                sum1 += cnt * k;
                ::cnt[i][j][k] = sum2 - k * cnt2 + k * cnt1 - sum1;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0] + cnt[i][j][str[i][j] - 'a' + 1];
            for(int k = 1 ; k <= 26 ; ++k){
                cnt[i][j][k] += cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k];
            }
        }
    }
    ans = 6996696669969696;
    for(int i = 1 ; i <= k ; ++i){
        long long res = cnt[n][m][0];
        res += get(a[i] , b[i] , c[i] , d[i] , e[i] - 'a' + 1);
        ans = min(ans , res);
    }
    printf("%lld\n" , ans);
}