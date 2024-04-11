#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int K = 12;
int n , k;
int arr[N];
long long bit[K][N];
void update(int x , int idx , long long val){
    while(idx <= n + 1){
        bit[x][idx] += val;
        idx += idx & -idx;
    }
}
long long query(int x , int idx){
    long long res = 0;
    while(idx){
        res += bit[x][idx];
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    ++k;
    update(0 , 1 , 1);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= k ; ++j){
            update(j , arr[i] + 1 , query(j - 1 , arr[i]));
        }
    }
    printf("%lld" , query(k , n + 1));
}