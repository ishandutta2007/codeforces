#include "bits/stdc++.h"
using namespace std;
int v;
int arr[10];
int mn = 1;
int ans[1 << 20];
int n = 0;
int main(){
    cin >> v;
    for(int i = 1 ; i <= 9 ; ++i){
        cin >> arr[i];
    }
    for(int i = 2 ; i <= 9 ; ++i){
        if(arr[i] <= arr[mn]){
            mn = i;
        }
    }
    while(v >= arr[mn]){
        ans[++n] = mn;
        v -= arr[mn];
    }
    int ptr = 1;
    while(v && ptr <= n){
        for(int i = 9 ; i > mn ; --i){
            if(arr[i] <= v + arr[mn]){
                v -= arr[i];
                v += arr[mn];
                ans[ptr] = i;
                break;
            }
        }
        ++ptr;
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d" , ans[i]);
    }
    if(!n){
        cout << -1;
    }
}