#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int a , b , c;
bool dp[N];
int main(){
    cin >> a >> b >> c;
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ; i <= c ; ++i){
        if(i >= a){
            dp[i] = dp[i - a];
        }
        if(i >= b){
            dp[i] |= dp[i - b];
        }
    }
    if(dp[c]){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}