#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1E5;
unordered_map<int, int> mp;

int modpow(int b, int e, int mod)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return b % mod;
    return (long long) (b % mod) * (modpow(b, e - 1, mod)) % mod;
}

int main()
{
    int n, p, k;
    cin >> n >> p >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int term = (modpow(a, 4, p) - (((long long) k * a) % p) + p) % p;
        if (mp.find(term) == mp.end())
            mp[term] = 1;
        else
        {
            ans += mp[term];
            mp[term]++;
        }
    }
    cout << ans;

    return 0;
}