#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
list<int> primes[N];
void sieve(){
    for(int i = 2 ; i < N ; ++i){
        if(!primes[i].size()){
            for(int j = i ; j < N ; j += i){
                primes[j].push_back(i);
            }
        }
    }
}
int ans = 1;
int dp[N] = {0};
int n;
int main(){
    sieve();
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        for(list<int>::iterator it = primes[temp].begin() ; it != primes[temp].end() ; ++it){
            dp[temp] = max(dp[temp],dp[*it] + 1);
        }
        for(list<int>::iterator it = primes[temp].begin() ; it != primes[temp].end() ; ++it){
            dp[*it] = dp[temp];
        }
        ans = max(ans , dp[temp]);
    }
    cout << ans;
}