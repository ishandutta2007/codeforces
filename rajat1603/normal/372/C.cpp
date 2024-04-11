#include "bits/stdc++.h"
using namespace std;
const int N = 150005;
const int M = 310;
int n , m , d;
int a[M];
int b[M];
int t[M];
long long dp[2][N] = {0};
int main(){
    cin >> n >> m >> d;
    for(int i = 1 ; i <= m ; ++i){
        cin >> a[i] >> b[i] >> t[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        long long ll = -t[i] + t[i - 1];
        ll *= d;
        long long rr = t[i] - t[i - 1];
        rr *= d;
        list < int > window;
        for(int j = 1 ; j <= min(1LL * n , rr) ; ++j){
            while(!window.empty() && dp[!(i & 1)][window.back()] <= dp[!(i & 1)][j]){
                window.pop_back();
            }
            window.push_back(j);
        }
        for(int j = 1 ; j <= n ; ++j){
            ++ll;
            ++rr;
            while(!window.empty() && window.front() < ll){
                window.pop_front();
            }
            if(rr <= n){
                while(!window.empty() && dp[!(i & 1)][window.back()] <= dp[!(i & 1)][rr]){
                    window.pop_back();
                }
                window.push_back(rr);
            }
            dp[i & 1][j] = dp[!(i & 1)][window.front()] + b[i] - abs(j - a[i]);
        }
        window.clear();
    }
    cout << *max_element(dp[m & 1] + 1 , dp[m & 1] + n + 1);
}