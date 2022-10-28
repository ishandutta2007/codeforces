#include "bits/stdc++.h"
using namespace std;
const int N = 3;
const int M = 300;
string winner[2] = {"BitLGM" , "BitAryo"};
int n;
int arr[N];
bool dp[M * M * M] = {0};
int a[N];
int decode(int a[]){
    int res = 0;
    for(int i = 0 ; i < n ; ++i){
        res = res * M + a[i];
    }
    return res;
}
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
    if(n == 3){
        cout << winner[!(arr[0] ^ arr[1] ^ arr[2])];
        return 0;
    }
    int sz = decode(arr);
    for(int i = 1 ; i <= sz ; ++i){
        int temp = i;
        for(int j = n-1 ; j >= 0 ; --j){
            a[j] = temp % M;
            temp /= M;
        }
        dp[i] = 1;
        for(int j = 0 ; j < n ; ++j){
            for(int x = 1 ; x <= a[j] ; ++x){
                a[j] -= x;
                dp[i] &= dp[decode(a)];
                a[j] += x;
            }
        }
        int mn = INT_MAX;
        for(int j = 0 ; j < n ; ++j){
            mn = min(mn , a[j]);
        }
        for(int x = 1 ; x <= mn ; ++x){
            for(int j = 0 ; j < n ; ++j){
                a[j] -= x;
            }
            dp[i] &= dp[decode(a)];
            for(int j = 0 ; j < n ; ++j){
                a[j] += x;
            }
        }
        dp[i] ^= 1;
    }
    cout << winner[!dp[sz]];
}