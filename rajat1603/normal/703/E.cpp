#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int MX = 7e3 + 3;
int n;
vector < long long > v;
long long k , arr[N] , inp[N];
pair < int , long long > dp[N][MX];
int prv[N][MX];
int main(){
    scanf("%d %lld" , &n , &k);
    v.clear();
    for(int i = 1 ; 1LL * i * i <= k ; ++i){
        if(k % i == 0){
            v.emplace_back(i);
            if((k / i) != i){
                v.emplace_back(k / i);
            }
        }
    }
    sort(v.begin() , v.end());
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , arr + i);
        inp[i] = arr[i];
        arr[i] = __gcd(arr[i] , k);
    }
    if(k == 1){
        printf("1\n%d\n" , min_element(inp + 1 , inp + 1 + n) - inp);
        return 0;
    }
    for(int i = 1 ; i < v.size() ; ++i){
        dp[0][i] = {N , N};
    }
    dp[0][0] = {0 , 0};
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < v.size() ; ++j){
            long long val = v[j] / __gcd(v[j] , arr[i]);
            int pos = lower_bound(v.begin() , v.end() , val) - v.begin();
            auto it = dp[i - 1][pos];
            it.first += 1;
            it.second += inp[i];
            dp[i][j] = min(dp[i - 1][j] , it);
            if(dp[i - 1][j] == dp[i][j]){
                prv[i][j] = j;
            }
            else{
                prv[i][j] = pos;
            }
        }
    }
    if(dp[n][v.size() - 1].first >= N){
        printf("-1\n");
        return 0;
    }
    printf("%d\n" , dp[n][v.size() - 1].first);
    int cur = n;
    int val = v.size() - 1;
    while(cur > 0){
        if(prv[cur][val] != val){
            printf("%d " , cur);
        }
        val = prv[cur][val];
        --cur;
    }
}