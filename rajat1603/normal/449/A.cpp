#include "bits/stdc++.h"
using namespace std;
long long n , m , k;
long long ans = 0;
long long solve(long long x , long long y){
    if(y < 1 || x < 1){
        return -1;
    }
    return max((n / x) * (m / y) , (m / x) * (n / y));
}
int main(){
    cin >> n >> m >> k;
    if((n - 1) + (m - 1) < k){
        cout << "-1";
        return 0;
    }
    for(int i = 1 ; i <= 100000 ; ++i){
        ans = max(ans , solve(i , k + 2 - i));
        ans = max(ans , solve(max(n , m) / i , k + 2 - (max(n , m) / i)));
    }
    cout << ans;
}