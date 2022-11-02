#include <bits/stdc++.h>
using namespace std;

long long M = 998244353;

int main(){
    int n;
    cin >> n;

    long long f = 1;
    long long ans = 0;
    for(int i = 1; i<=n; i++){
        f*=i;
        f%=M;
    }


    long long prod = 1;
    for(int i = n - 1; i>=1; i--){
        prod *= (i + 1);
        prod %= M;
        ans += (f - prod);
        ans %= M;
    }

    cout << ((ans + f) + M) % M;


}