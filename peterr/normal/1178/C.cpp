#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int modpow(int base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % MOD;
    int temp = modpow(base, exp / 2);
    if (exp % 2 == 0)
        return (long long) temp * temp % MOD;
    return (long long) ((long long) temp * temp % MOD) * base % MOD;
}

int main()
{
    int w, h;
    cin >> w >> h;
    cout << modpow(2, w + h) << endl;
    return 0;
}