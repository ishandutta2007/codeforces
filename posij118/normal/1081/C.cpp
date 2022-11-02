#include <bits/stdc++.h>
using namespace std;

long long M = 998244353;

long long po(long long a, int x){
    if(x == 1) return a;
    long long half = po(a, x /2);
    if(x % 2 == 0) return (half * half) % M;
    else return (((half * half) % M) * a) % M;
}

int main(){
    long long n, m, k;
    cin >> n >> m >> k;

    long long ans = 1;
    for(int i = 1; i<=n - 1; i++){
        ans *= i;
        ans %= M;
    }

    for(int i = 1; i<=k; i++){
        ans *= po(i, M - 2);
        ans %= M;
    }

    for(int i = 1; i<=n - 1 - k; i++){
        ans *= po(i, M - 2);
        ans %= M;
    }

    for(int i = 0; i<k; i++){
        ans *= (m - 1);
        ans %= M;
    }

    ans *= m;
    ans %= M;

    cout << ans;
}