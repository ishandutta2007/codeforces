#include "bits/stdc++.h"
using namespace std;
long long ans;
int k2 , k3 , k5 , k6;
int main(){
    cin >> k2 >> k3 >> k5 >> k6;
    ans = 0;
    while(min(k2 , min(k5 , k6))){
        --k2;
        --k5;
        --k6;
        ans += 256;
    }
    while(min(k2 , k3)){
        ans += 32;
        --k2;
        --k3;
    }
    cout << ans;
}