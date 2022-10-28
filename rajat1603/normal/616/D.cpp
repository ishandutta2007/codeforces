#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , k;
int arr[N];
int cnt[1 << 20];
int ans = 0;
int ansl , ansr;
int cur = 0;
int l = 1;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        ++cnt[arr[i]];
        if(cnt[arr[i]] == 1){
            ++cur;
        }
        while(cur > k){
            --cnt[arr[l]];
            if(cnt[arr[l]] == 0){
                --cur;
            }
            ++l;
        }
        if(i - l + 1 > ans){
            ans = i - l + 1;
            ansl = l;
            ansr = i;
        }
    }
    printf("%d %d" , ansl , ansr);
}