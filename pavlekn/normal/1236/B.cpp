#include<bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

const int mod = 1e9 + 7;

int pow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a % mod;
    }
    int ans = pow(a, n / 2);
    ans *= ans;
    ans %= mod;
    if (n % 2 == 1)
    {
        return (ans * a) % mod;
    }
    return ans % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = pow((pow(2ll, m) - 1), n);
    cout << (ans + mod) % mod << endl;
    return 0;
}