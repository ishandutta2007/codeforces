#include "bits/stdc++.h"
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<1) + (x<<3) + c - '0';
        c = getchar();
    }
    return x;
}
const int N = 100001;
int arr[N];
int l[N];
int r;
int n;
int ans = 0;
int main(){
    n = scan();
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = scan();
        l[i] = 1;
        if(arr[i] > arr[i-1]){
            l[i] = l[i-1] + 1;
        }
    }
    for(int i = n ; i >= 1 ; --i){
        if(arr[i-1] < arr[i+1] - 1)
            ans = max(ans , r + l[i-1] + 1);
        else
            ans = max(ans , max(l[i-1] + 1 , r + 1));
        if(arr[i] < arr[i+1]){
            ++r;
        }
        else{
            r = 1;
        }
    }
    printf("%d" , ans);
}