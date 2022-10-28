#include "bits/stdc++.h"
using namespace std;
const int N = 102;
int sum[N][N] = {0};
int n;
int a , b , c , d;
int ans = 0;
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d %d %d %d" , &a , &b , &c , &d);
        sum[a][b]++;
        sum[a][d + 1]--;
        sum[c + 1][b]--;
        sum[c + 1][d + 1]++;
    }
    for(int i = 1 ; i < N ; ++i){
        for(int j = 1 ; j < N ; ++j){
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            ans += sum[i][j];
        }
    }
    printf("%d\n" , ans);
}