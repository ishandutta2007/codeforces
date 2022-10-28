#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int arr1[N];
int arr2[N];
int last[N];
bool done[N];
bool check(int day){
    for(int i = 1 ; i <= m ; ++i){
        last[i] = -1;
    }
    for(int i = 1 ; i <= day ; ++i){
        last[arr1[i]] = max(last[arr1[i]] , i);
    }
    for(int i = 1 ; i <= m ; ++i){
        if(last[i] == -1){
            return 0;
        }
    }
    int ptr = 1;
    for(int i = 1 ; i <= day ; ++i){
        done[i] = 0;
    }
    for(int i = 1 ; i <= day ; ++i){
        if(arr1[i] && i == last[arr1[i]]){
            int req = arr2[arr1[i]];
            while(ptr < i && req){
                if(done[ptr]){
                    ++ptr;
                }
                else{
                    done[ptr] = 1;
                    --req;
                    ++ptr;
                }
            }
            if(req){
                return 0;
            }
            done[i] = 1;
        }
    }
    return 1;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr1 + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , arr2 + i);
    }
    if(!check(n)){
        printf("-1\n");
    }
    else{
        int l = 1;
        int r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        printf("%d\n" , l);
    }
}