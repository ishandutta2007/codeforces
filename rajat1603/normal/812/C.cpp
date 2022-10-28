#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , s;
int arr[N];
long long cst;
long long tmp[N];
bool check(int k){
    for(int i = 1 ; i <= n ; ++i){
        tmp[i] = arr[i] + 1LL * k * i;
    }
    sort(tmp + 1 , tmp + 1 + n);
    cst = 0;
    for(int i = 1 ; i <= k ; ++i){
        cst += tmp[i];
    }
    return cst <= s;
}
int main(){
    scanf("%d %d" , &n , &s);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    int l = 0;
    int r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    check(l);
    printf("%d %lld\n" , l , cst);
}