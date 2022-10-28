#include "bits/stdc++.h"
using namespace std;
int k , r;
long long ans;
int main(){
    ans = 1e15;
    cin >> k >> r;
    for(int x = 0 ; x <= 10000000 ; ++x){
        long long tmp = 10LL * x + r;
        if(tmp % k == 0){
            ans = tmp / k;
            break;
        }
    }
    for(int x = 1 ; x <= 10000000 ; ++x){
        long long tmp = 10LL * x;
        if(tmp % k == 0){
            ans = min(ans , tmp / k);
            break;
        }
    }
    cout << ans;
}