#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define mod 1000003
#define pi acos(-1)
using namespace std;

long long n, k, deno, nume;

long long expo(long long a, long long b) {
    long long ret = 1;
    for (int i = 62; i >= 0; i--) {
        ret *= ret;
        ret %= mod;
        if ((1ll << i) & b) {
            ret *= a;
            ret %= mod;
        }
    }
    return ret;
}

int main() {
    cin >> n >> k;
    if (n <= 62 && (1ll << n) < k) {
        cout << "1 1";
        return 0;
    }
    long long all = 1;
    long long st = expo(2, n);
    if (k >= mod) all = 0;
    else {
        for (long long i = 0; i < k; i++) {
            all *= (st + mod - i); 
            all %= mod;
        }
        all *= expo(expo(500002, n), k);
    }
    deno = expo(expo(2, n), k);
    long long cnt = n;
    long long b = 2;
    while (b < k) {
        cnt += (k - 1) / b;
        b *= 2;
    }
    deno *= expo(500002, cnt);
    deno %= mod;
    nume = deno * all;
    nume %= mod;
    nume = (deno - nume + mod) % mod;
    cout << nume << ' ' << deno;
}