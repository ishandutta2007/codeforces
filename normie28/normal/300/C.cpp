#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
       
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
long double eps = 1e-6;
const long double pi = 3.14159265358979323846;
 
const int N = 1e6 + 100;
long long fact[N], modd = INF + 7;
int n, a, b;
bool read()
{
        if (!(cin >> a >> b >> n))
                return false;
        assert(a >= 1 && a <= 9);
        assert(b >= a + 1 && b <= 9);
        assert(n >= 1 && n <= (int)1e6);
        return true;
}
long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
bool check(long long val, int a, int b) {
        while (val > 0) {
                if (val % 10 == a || val % 10 == b) {
                        val /= 10;
                } else return false;
        }
        return true;
}
void initfact() {
        fact[0] = 1;
        for(int i = 1; i < N; i++) {
                fact[i] = (fact[i-1] * i);
                fact[i] %= modd;
        }
}
long long getC(int n, int i) {
        long long res = fact[n];
        long long div = fact[n-i] * fact[i];
        div %= modd;  div = binpow(div, modd - 2, modd);
        return (res * div) % modd;
}
void solve()
{
        long long ans = 0;
        for(int i = 0; i <= n; i++) {
                long long expsum = a * i + b*(n-i);
                if (check(expsum, a, b)) {
                        ans += getC(n, i);
                        ans %= modd;
                }
        }
        cout << ans << endl;
}
 
int main(){
        initfact();
        assert(read());
        solve();
}