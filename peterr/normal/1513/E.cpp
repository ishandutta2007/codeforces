#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5;
int a[MAXN];
int fac[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        e >>= 1;
        b = (int) ((long long) b * b % MOD);
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << "0\n";
        return 0;
    }
    sort(a, a + n);
    int target = (int) (sum / n);
    int sources = 0;
    int sinks = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > target)
        {
            sources++;
        }
        else if (a[i] < target)
        {
            sinks++;
        }
    }
    if (sources <= 1 || sinks <= 1)
    {
        int ans = fac[n];
        int ptr = 0;
        while (ptr < n)
        {
            int val = a[ptr];
            int cnt = 0;
            while (ptr < n && a[ptr] == val)
            {
                ptr++;
                cnt++;
            }
            ans = (int) ((long long) ans * modinv(fac[cnt]) % MOD);
        }
        cout << ans << "\n";
        return 0;
    }
    else
    {
        int ans = 2;
        ans = (int) ((long long) ans * fac[sinks] % MOD);
        ans = (int) ((long long) ans * fac[sources] % MOD);
        int neutral = n - sources - sinks;
        for (int i = 0; i < neutral; i++)
        {
            ans = (int) ((long long) ans * (sources + sinks + 1 + i) % MOD);
        }
        int ptr = 0;
        while (ptr < n)
        {
            int val = a[ptr];
            int cnt = 0;
            while (ptr < n && a[ptr] == val)
            {
                ptr++;
                cnt++;
            }
            ans = (int) ((long long) ans * modinv(fac[cnt]) % MOD);
        }
        cout << ans << "\n";
    }
    return 0;
}