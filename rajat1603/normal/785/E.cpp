#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int M = N;
const int SQN = 650;
int n , q;
int arr[N];
int x , y;
int l , r;
int start[SQN];
int finish[SQN];
int block[N];
int bit[SQN][M];
void update(int i , int idx , int val){
    while(idx < M){
        bit[i][idx] += val;
        idx += idx & -idx;
    }
}
int sum(int i , int idx){
    int res = 0;
    while(idx){
        res += bit[i][idx];
        idx -= idx & -idx;
    }
    return res;
}
long long inv = 0;
int get(int l , int r , int x){
    int res = 0;
    for(int i = block[l] ; i <= block[r] ; ++i){
        if(start[i] >= l && finish[i] <= r){
            res += sum(i , x);
        }
        else{
            for(int j = max(start[i] , l) ; j <= min(finish[i] , r) ; ++j){
                res += (arr[j] <= x);
            }
        }
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = i;
    }
    int i = 1;
    int cur = 0;
    while(i <= n){
        int j = i;
        start[++cur] = i;
        while(j <= n && j < i + SQN){
            block[j] = cur;
            update(cur , arr[j] , 1);
            ++j;
        }
        finish[cur] = j - 1;
        i = j;
    }
    while(q--){
        scanf("%d %d" , &l , &r);
        if(l != r){
            x = l;
            y = arr[r];
            int oldl = arr[l];
            inv -= x - 1 - get(1 , x - 1 , arr[x]);
            inv -= get(x + 1 , n , arr[x] - 1);
            update(block[x] , y , 1);
            update(block[x] , arr[x] , -1);
            arr[x] = y;
            inv += x - 1 - get(1 , x - 1 , arr[x]);
            inv += get(x + 1 , n , arr[x] - 1);
            x = r;
            y = oldl;
            inv -= x - 1 - get(1 , x - 1 , arr[x]);
            inv -= get(x + 1 , n , arr[x] - 1);
            update(block[x] , y , 1);
            update(block[x] , arr[x] , -1);
            arr[x] = y;
            inv += x - 1 - get(1 , x - 1 , arr[x]);
            inv += get(x + 1 , n , arr[x] - 1);
        }
        printf("%lld\n" , inv);
    }
}