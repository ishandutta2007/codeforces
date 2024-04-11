#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int SZ = 1 << 16;
const int MAX = 54;
int n , cnt = 0;
int prime[MAX];
int arr[N];
int dp[N][SZ];
int main(){
    for(int i = 2 ; i < MAX ; ++i){
        if(!prime[i]){
            for(int j = i ; j < MAX ; j += i){
                prime[j] |= 1 << cnt;
            }
            ++cnt;
        }
    }
    cin >> n;
    string str;
    getchar();
    getline(cin , str);
    stringstream ss(str);
    for(int i = 1 ; i <= n ; ++i){
        ss >> arr[i];
    }
    for(int i = n ; i >= 1 ; --i){
        for(int j = 0 ; j < SZ ; ++j){
            dp[i][j] = INT_MAX;
            for(int k = 1 ; k < MAX ; ++k){
                if(!(prime[k] & j)){
                    dp[i][j] = min(dp[i][j] , abs(k - arr[i]) + dp[i + 1][j ^ prime[k]]);
                }
            }
        }
    }
    int maxb = 0;
    for(int i = 1 ; i <= n ; ++i){
        int go = 1;
        for(int k = 1 ; k < MAX ; ++k){
            if(!(maxb & prime[k])){
                if(dp[i + 1][maxb | prime[k]] + abs(k - arr[i]) < dp[i + 1][maxb | prime[go]] + abs(go - arr[i])){
                    go = k;
                }
            }
        }
        maxb |= prime[go];
        cout << go << " ";
    }
}