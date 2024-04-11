#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 1 << 10;
int n , k , x;
int arr[N];
int cnt[M];
int tmp[M];
int main(){
    memset(cnt , 0 , sizeof(cnt));
    scanf("%d %d %d" , &n , &k , &x);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        ++cnt[arr[i]];
    }
    for(int i = 1 ; i <= k ; ++i){
        memset(tmp , 0 , sizeof(tmp));
        bool cur = 0;
        for(int j = 0 ; j < M ; ++j){
            if(cnt[j]){
                if(cnt[j] & 1){
                    if(cur){
                        tmp[j] += cnt[j] + 1 >> 1;
                        tmp[j ^ x] += cnt[j] >> 1;
                    }
                    else{
                        tmp[j] += cnt[j] >> 1;
                        tmp[j ^ x] += cnt[j] + 1 >> 1;
                    }
                    cur ^= 1;
                }
                else{
                    tmp[j] += cnt[j] >> 1;
                    tmp[j ^ x] += cnt[j] >> 1;
                }
            } 
        }
        memcpy(cnt , tmp , sizeof(int) * M);
    }
    int mn = M;
    int mx = 0;
    for(int i = 0 ; i < M ; ++i){
        if(cnt[i]){
            mn = min(mn , i);
            mx = max(mx , i);
        }
    }
    printf("%d %d\n" , mx , mn);
}