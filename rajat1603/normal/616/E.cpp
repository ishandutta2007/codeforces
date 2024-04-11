#include "bits/stdc++.h"
using namespace std;
const long long mod = 1e9 + 7;
long long n , m;
long long ans;
long long mult(long long a , long long b){
    long long res = a % mod;
    res *= b % mod;
    return res % mod;
}
long long sum(long long x){
    if(x & 1){
        return mult(((x + 1) >> 1) % mod , x % mod);
    }
    else{
        return mult((x >> 1) % mod , (x + 1) % mod);
    }
}
long long get(long long a , long long b){
    long long res = sum(b);
    res -= sum(a - 1);
    res %= mod;
    if(res < 0){
        res += mod;
    }
    return res;
}
long long solve1(long long x){
    long long ans = 0;
    long long r = n / x;
    long long l = 1 + (n / (x + 1));
    r = min(m , r);
    if(l > r){
        return 0;
    }
    ans += mult(n % mod , (r - l + 1) % mod);
    ans -= mult(x % mod , get(l , r));
    ans %= mod;
    return ans;
}
long long solve(long long n){
    ans = 0;
    if(m >= n){
        ans += mult((m - n) % mod , n % mod);
        m = n - 1;
    }
    long long i = 1;
    while(i * i <= n){
        ans += solve1(i);
        if((n / i) != i){
            ans += solve1(n / i);
        }
        ans %= mod;
        ++i;
    }
    return ans;
}
int main(){
    while(cin >> n >> m){
        cout << solve(n) << endl;
    }
}