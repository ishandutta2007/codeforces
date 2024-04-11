#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
string str;
int pre0[N];
int pre1[N];
int suf0[N];
int suf1[N];
int ans = 1;
int main(){
    cin >> n;
    cin >> str;
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = str[i - 1] - '0';
    }
    pre0[0] = pre1[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        pre0[i] = pre0[i - 1];
        pre1[i] = pre1[i - 1];
        if(arr[i]){
            pre1[i] = max(pre1[i] , pre0[i] + 1);
        }
        else{
            pre0[i] = max(pre0[i] , pre1[i] + 1);
        }
    }
    suf0[n + 1] = suf1[n + 1] = 0;
    for(int i = n ; i >= 1 ; --i){
        suf0[i] = suf0[i + 1];
        suf1[i] = suf1[i + 1];
        if(arr[i]){
            suf1[i] = max(suf1[i] , suf0[i] + 1);
        }
        else{
            suf0[i] = max(suf0[i] , suf1[i] + 1);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        ans = max(ans , pre0[i] + suf1[i + 1]);
        ans = max(ans , pre1[i] + suf0[i + 1]);
        if(arr[i]){
            ans = max(ans , pre1[i - 1] + 1 + suf1[i + 1]);
        }
        else{
            ans = max(ans , pre0[i - 1] + 1 + suf0[i + 1]);
        }
    }/*
    if(n >= 2){
        for(int i = 1 ; i < n ; ++i){
            if(arr[i] == 0 && arr[i + 1] == 0){
                ans = max(ans , pre0[i - 1] + suf0[i + 2] + 1);
            }
            else if(arr[i] == 0 && arr[i + 1] == 1){
                ans = max(ans , pre0[i - 1] + suf1[i + 2] + 2);
            }
            else if(arr[i] == 1 && arr[i + 1] == 0){
                ans = max(ans , pre1[i - 1] + suf0[i + 2] + 2);
            }
            else{
                ans = max(ans , pre1[i - 1] + suf1[i + 2] + 1);
            }
        }
    }*/
    int len = 1;
    int strt = 1;
    arr[n + 1] = arr[n];
    for(int i = 2 ; i <= n + 1 ; ++i){
        if(arr[i] != arr[i - 1]){
            ++len;
        }
        else{
            if(arr[strt] == 0 && arr[i - 1] == 0){
                ans = max(ans , pre0[strt - 1] + suf0[i] + len);
            }
            else if(arr[strt] == 0 && arr[i - 1] == 1){
                ans = max(ans , pre0[strt - 1] + suf1[i] + len);
            }
            else if(arr[strt] == 1 && arr[i - 1] == 0){
                ans = max(ans , pre1[strt - 1] + suf0[i] + len);
            }
            else{
                ans = max(ans , pre1[strt - 1] + suf1[i] + len);
            }
            strt = i;
            len = 1;
        }
    }
    printf("%d\n" , ans);
}