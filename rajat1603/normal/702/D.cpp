#include "bits/stdc++.h"
using namespace std;
long long d , k , a , b , t;
int main(){
    cin >> d >> k >> a >> b >> t;
    if(d <= k){
        cout << d * a;
        return 0;
    }
    long long ans;
    ans = d * b;
    long long val = a * k + t - k * b;
    long long x;
    if(val > 0){
        x = 1;
    }
    else{
        x = d / k;
    }
    ans = min(ans , x * val + d * b - t);
    ans = min(ans , d * a + ((d - 1) / k) * t);
    cout << ans;
}