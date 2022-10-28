#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
long long k;
int x , y;
long long arr[N][N];
int main(){
    cin >> n >> m;
    cin >> k;
    cin >> x >> y;
    memset(arr , 0 , sizeof(arr));
    if(n == 1){
        long long tot = k / m;
        for(int i = 1 ; i <= m ; ++i){
            arr[1][i] = tot;
        }
        k %= m;
        for(int i = 1 ; i <= m ; ++i){
            if(k){
                ++arr[1][i];
                --k;
            }
        }
    }
    else{
        long long tot = k / ((2LL * n - 2LL) * m);
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= m ; ++j){
                if(i == 1){
                    arr[i][j] += tot;
                }
                else if(i == n){
                    arr[i][j] += tot;
                }
                else{
                    arr[i][j] += 2LL * tot;
                }
            }
        }
        k %= (2LL * n - 2LL) * m;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= m ; ++j){
                if(k){
                    ++arr[i][j];
                    --k;
                }
            }
        }
        for(int i = n - 1 ; i > 1 ; --i){
            for(int j = 1 ; j <= m ; ++j){
                if(k){
                    ++arr[i][j];
                    --k;
                }
            }
        }
    }
    long long mn = 1e18;
    long long mx = -1e9;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            mx = max(mx , arr[i][j]);
            mn = min(mn , arr[i][j]);
        }
    }
    printf("%lld %lld %lld\n" , mx , mn , arr[x][y]);
}