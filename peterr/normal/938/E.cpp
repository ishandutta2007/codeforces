#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E6;
int a[MAXN];
int fac[MAXN + 1];
int invfac[MAXN + 1];

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
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invfac[i] = modinv(fac[i]);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    int p = 0;
    for (int i = 0; i < n && a[i] < a[n - 1]; i++)
    {
        while (a[p] < a[i])
            p++;
        int B = p;
        int A = n - 1 - B;
        int temp = (int) ((long long) fac[n] * modinv(A + 1) % MOD);
        temp = (int) ((long long) temp * a[i] % MOD);
        ans += temp;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}