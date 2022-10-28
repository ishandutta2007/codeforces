#include "bits/stdc++.h"
using namespace std;
const int N = 4005;
const int SQN = 1 + sqrt(2 * N);
const int ALSOSQN = 1.8 * SQN;
int n;
int arr[N];
int pre[N];
int dp1[N][ALSOSQN][SQN];
int dp2[N][ALSOSQN][SQN];
char calc[N][ALSOSQN][SQN];
int sum(int l , int r){
    return pre[r] - pre[l - 1];
}
int solve1(int l , int r , int k);
int solve2(int l , int r , int k){
    if(r - k + 1 < l){
        return 0;
    }
    if(calc[l][(n + 1 - r) - l + k][k] & 2){
        return dp2[l][(n + 1 - r) - l + k][k];
    }
    int res = 1e9;
    res = min(res , solve1(l , r - k , k) - sum(r - k + 1 , r));
    if(r - k >= l){
        res = min(res , solve1(l , r - k - 1 , k + 1) - sum(r - k , r));
    }
    calc[l][(n + 1 - r) - l + k][k] |= 2;
    return dp2[l][(n + 1 - r) - l + k][k] = res;
}
int solve1(int l , int r , int k){
    if(l + k - 1 > r){
        return 0;
    }
    if(calc[l][(n + 1 - r) - l + k][k] & 1){
        return dp1[l][(n + 1 - r) - l + k][k];
    }
    int res = -1e9;
    res = max(res , sum(l , l + k - 1) + solve2(l + k , r , k));
    if(l + k <= r){
        res = max(res , sum(l , l + k) + solve2(l + k + 1 , r , k + 1));
    }
    calc[l][(n + 1 - r) - l + k][k] |= 1;
    return dp1[l][(n + 1 - r) - l + k][k] = res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    pre[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1] + arr[i];
    }
    printf("%d\n" , solve1(1 , n , 1));
}