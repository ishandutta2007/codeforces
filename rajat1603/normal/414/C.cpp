#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int n , p;
int arr[1 << N];
int q;
int inp;
long long val[N];
long long rev[N];
int tmp[1 << N];
long long ans;
inline void put(long long x){
    if(x < 10){
        putchar('0' + x);
    }
    else{
        put(x / 10);
        putchar('0' + (x % 10));
    }
}
int main(){
    scanf("%d" , &n);
    p = 1 << n;
    for(int i = 0 ; i < p ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 0 ; i < n ; ++i){
        long long val = 0;
        long long rev = 0;
        int len = 1 << i;
        for(int j = 0 ; j < p ; j += len + len){
            int l1 = j;
            int r1 = j + len - 1;
            int l2 = j + len;
            int r2 = j + len + len - 1;
            int idx = 0;
            int idx2 = l2;
            int idx3 = l2;
            for(int k = l1 ; k <= r1 ; ++k){
                while(idx2 <= r2 && arr[idx2] < arr[k]){
                    tmp[idx++] = arr[idx2];
                    ++idx2;
                }
                tmp[idx++] = arr[k];
                idx3 = max(idx3 , idx2);
                while(idx3 <= r2 && arr[idx3] <= arr[k]){
                    ++idx3;
                }
                val += idx2 - l2;
                rev += r2 - idx3 + 1;
            }
            memcpy(arr + l1 , tmp , idx * sizeof(int));
        }
        ans += val;
        ::val[i] = val;
        ::rev[i] = rev;
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%d" , &inp);
        while(inp--){
            ans += rev[inp] - val[inp];
            swap(val[inp] , rev[inp]);
        }
        put(ans);
        putchar('\n');
    }
}