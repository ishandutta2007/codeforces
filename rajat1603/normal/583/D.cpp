#include "bits/stdc++.h"
using namespace std;
const int N = 301;
int bit[N];
void update(int idx , int val){
    while(idx < N){
        bit[idx] = max(bit[idx] , val);
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx >= 1){
        res = max(res , bit[idx]);
        idx -= idx & -idx;
    }
    return res;
}
int n , t;
int arr[N];
int bl;
int ans = 0;
int cnt = 0;
int val = 0;
int main(){
    scanf("%d %d" , &n , &t);
    map < int , int > mm;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        if(i > 1){
            if(arr[i] != arr[i - 1]){
                bl = 0;
            }
        }
        mm[arr[i]]++;
    }
    for(auto it : mm){
        val = max(val , it.second);
    }
    if(bl){
        printf("%d\n" , n * t);
        return 0;
    }
    for(int tt = 1 ; tt <= t ; ++tt){
        for(int i = 1 ; i <= n ; ++i){
            int x = query(arr[i]) + 1;
            ans = max(ans , x);
            update(arr[i] , x);
        }
        if(tt == n * n * 2){
            ans += (t - n * n * 2) * val;
            break;
        }
    }
    printf("%d\n" , ans);
}