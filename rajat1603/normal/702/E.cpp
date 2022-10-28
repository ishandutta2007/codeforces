#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 35;
int n;
int nxt[LN][N];
long long sum[LN][N];
int mini[LN][N];
long long k;
void query(int node , long long dist){
    long long s = 0;
    int m = 1e9 + 9;
    for(int i = 0 ; i < LN ; ++i){
        if(dist & (1LL << i)){
            m = min(m , mini[i][node]);
            s += sum[i][node];
            node = nxt[i][node];
        }
    }
    printf("%lld %d\n" , s , m);
}
int main(){
    scanf("%d %lld" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &nxt[0][i]);
        ++nxt[0][i];
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , &sum[0][i]);
        mini[0][i] = sum[0][i];
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][nxt[i - 1][j]];
            mini[i][j] = min(mini[i - 1][j] , mini[i - 1][nxt[i - 1][j]]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        query(i , k);
    }
}