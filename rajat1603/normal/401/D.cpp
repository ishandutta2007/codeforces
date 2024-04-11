#include "bits/stdc++.h"
using namespace std;
const int N = 19;
const int M = 100;
string str;
int m;
int n;
int target = 0;
int cnt[10] = {0};
long long dp[1 << N][M] = {0};
int main(){
    cin >> str >> m;
    n = str.size();
    for(int i = 0 ; i < n ; ++i){
        target |= 1 << i;
        cnt[str[i] - '0']++;
    }
    dp[target][0] = 1;
    for(int i = target - 1 ; i >= 0 ; --i){
        for(int j = 0 ; j < m ; ++j){
            for(int k = 0 ; k < n ; ++k){
                if(!(i & (1 << k)) && (i || str[k] > '0')){
                    dp[i][j] += dp[i | (1 << k)][(j * 10 + str[k] - '0') % m];
                }
            }
        }
    }
    for(int i = 0 ; i < 10 ; ++i){
        while(cnt[i]){
            dp[0][0] /= cnt[i]--;
        }
    }
    cout << dp[0][0];
}