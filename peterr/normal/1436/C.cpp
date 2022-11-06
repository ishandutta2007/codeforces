#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MOD = 1E9 + 7;

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int fac(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans = (int) ((long long) ans * i % MOD);
    }
    return ans;
}

int choose(int n, int k)
{
    if (k > n)
        return 0;
    int ans = (int) ((long long) fac(n) * modinv(fac(k)) % MOD);
    return (int) ((long long) ans * modinv(fac(n - k)) % MOD);
}

int main()
{
    int n, x, pos;
    cin >> n >> x >> pos;
    int l = 0;
    int r = n;
    set<int> s;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid != pos)
            s.insert(mid);
        if (pos >= mid)
            l = mid + 1;
        else
            r = mid;
    }
    int above = 0;
    int below = 0;
    for (int y : s)
    {
        if (y > pos)
            above++;
        else
            below++;
    }
    int ans = 1;
    ans = (int) ((long long) ans * choose(x - 1, below) % MOD);
    ans = (int) ((long long) ans * fac(below) % MOD);
    ans = (int) ((long long) ans * choose(n - x, above) % MOD);
    ans = (int) ((long long) ans * fac(above) % MOD);
    int remain = n - 1 - (int) s.size();
    ans = (int) ((long long) ans * fac(remain) % MOD);
    cout << ans << "\n";
    return 0;
}