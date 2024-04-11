#include "bits/stdc++.h"
using namespace std;
const int N = 4005;
const int mod = 1e9 + 7;
int n;
int pascal[N][N] = {0};
int bell[N] = {0};
int ans = 0;
void pre(){
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        pascal[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j){
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            if(pascal[i][j] >= mod){
                pascal[i][j] -= mod;
            }
        }
    }
    bell[0] = 1;
    bell[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        bell[i] = 0;
        for(int k = 0 ; k < n ; ++k){
            bell[i] += (1LL * bell[k] * pascal[i - 1][k]) % mod;
            if(bell[i] >= mod){
                bell[i] -= mod;
            }
        }
    }
}
int main(){
    //b(n) = sum(k=0, n-1)b(k)*((n-1)Ck)
    //n*B(n-1) + nC2*B(n-2) + ....
    cin >> n;
    pre();
    for(int i = 1 ; i <= n ; ++i){
        ans += (1LL * pascal[n][i] * bell[n - i]) % mod;
        if(ans >= mod){
            ans -= mod;
        }
    }
    cout << ans;
}