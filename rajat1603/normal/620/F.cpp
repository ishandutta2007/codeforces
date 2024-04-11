#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 4;
const int M = 5e3 + 3;
const int MAX = 1e6 + 6;
int n , q;
int arr[N];
int l[M];
int r[M];
int ans[M];
int prexor[MAX];
int arr2[N];
int mx[N];
int main(){
    prexor[0] = 0;
    for(int i = 1 ; i < MAX ; ++i){
        prexor[i] = prexor[i - 1] ^ i;
    }
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        arr2[i] = prexor[arr[i]];
    }
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , l + i , r + i);
        ans[i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        int mxval = 0;
        for(int j = i ; j <= n ; ++j){
            mxval = max(mxval , arr2[i] ^ arr2[j] ^ (arr[i] < arr[j] ? arr[i] : arr[j]));
            mx[j] = mxval;
        }
        for(int j = 1 ; j <= q ; ++j){
            if(l[j] <= i){
                ans[j] = max(ans[j] , mx[r[j]]);
            }
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}