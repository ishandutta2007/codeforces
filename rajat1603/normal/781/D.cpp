#include "bits/stdc++.h"
using namespace std;
const int N = 505;
const int K = 60;
int n , m;
int a , b , c;
bool grid[K][N][N][2];
unsigned bit[2][N][1 + (N >> 5)];
unsigned tmp[1 + (N >> 5)];
void mult(int idx){
    memset(bit , 0 , sizeof(bit));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            for(int k = 0 ; k < 2 ; ++k){
                if(grid[idx - 1][i][j][k]){
                    bit[k][j][i >> 5] |= 1u << (i & 31);
                }
            }
        }
    }
    for(int cur = 0 ; cur < 2 ; ++cur){
        for(int i = 1 ; i <= n ; ++i){
            memset(tmp , 0 , sizeof(tmp));
            for(int j = 1 ; j <= n ; ++j){
                if(grid[idx - 1][i][j][cur]){
                    tmp[j >> 5] |= 1u << (j & 31);
                }
            }
            for(int j = 1 ; j <= n ; ++j){
                bool ok = 0;
                for(int k = 0 ; k <= (n >> 5) ; ++k){
                    if(tmp[k] & bit[!cur][j][k]){
                        ok = 1;
                        break;
                    }
                }
                if(ok){
                    grid[idx][i][j][cur] = 1;
                }
            }
        }
    }
}
bool vec[N];
bool temp[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        grid[0][a][b][c] = 1;
    }
    for(int i = 1 ; i < K ; ++i){
        mult(i);
    }
    vec[1] = 1;
    int cur = 0;
    long long ans = 0;
    for(int i = K - 1 ; i >= 0 ; --i){
        memset(temp , 0 , sizeof(temp));
        bool ok = 0;
        for(int j = 1 ; j <= n ; ++j){
            if(vec[j]){
                for(int k = 1 ; k <= n ; ++k){
                    if(grid[i][j][k][cur]){
                        temp[k] = 1;
                        ok = 1;
                    }
                }
            }
        }
        if(ok){
            cur ^= 1;
            ans += 1LL << i;
            memcpy(vec , temp , sizeof(vec));
        }
    }
    if(ans > 1000000000000000000LL){
        ans = -1;
    }
    printf("%lld\n" , ans);
}