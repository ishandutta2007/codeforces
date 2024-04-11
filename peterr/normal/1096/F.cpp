#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 998244353;
int arr[MAXN];
bool known[MAXN + 1];
int pre[MAXN + 1];
int bit[MAXN + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int power(int b, int p)
{
    int ans = 1;
    while (p > 0)
    {
        if ((p & 1) == 1)
        {
            ans = ((long long) ans * b) % MOD;
        }
        p >>= 1;
        b = ((long long) b * b) % MOD;
    }
    return ans;
}

int modinv(int x)
{
    return power(x, MOD - 2);
}

int main()
{
    int n;
    cin >> n;
    int negs = 0;
    int G = 0;
    int L = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == -1)
            negs++;
        else
        {
            known[arr[i]] = true;
            pre[arr[i]] = negs;
            G = (G - pre[arr[i]] + MOD) % MOD;
        }
    }
    G = (G + (long long) negs * (n - negs)) % MOD;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != -1)
        {
            ans = (ans + query(arr[i])) % MOD;
            inc(arr[i], 1);
        }
    }
    ans = (ans + ((long long) ((long long) negs * (negs - 1)) % MOD * modinv(4)) % MOD) % MOD;
    for (int i = 1; i <= n; i++)
    {
        if (known[i])
        {
            //ans = (ans + ((long long) (((long long) pre[i] * modinv(negs)) % MOD) * unknownGreater % MOD)) % MOD;
            G = (G - (negs - pre[i]) + MOD) % MOD;
            L = (L + pre[i]) % MOD;
        }
        else
        {
            ans = (ans + (((long long) G * modinv(negs)) % MOD)) % MOD;
            ans = (ans + (((long long) L * modinv(negs)) % MOD)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}