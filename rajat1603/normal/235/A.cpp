#include "bits/stdc++.h"
using namespace std;
int n;
long long ans = 0;
long long lcm(int a , int b , int c){
    long long res = a;
    res *= b;
    res /= __gcd(a , b);
    res /= __gcd(res , 1LL * c);
    res *= c;
    return res;
}
int main(){
    cin >> n;
    for(int i = max(1 , n - 50) ; i <= n ; ++i){
        for(int j = i ; j <= n ; ++j){
            for(int k = j ; k <= n ; ++k){
                ans = max(ans , lcm(i , j , k));
            }
        }
    }
    cout << ans;
}