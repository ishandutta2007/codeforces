#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 1E9 + 7;
int t[MAXN];
int fac[MAXN + 1];
int invFac[MAXN + 1];
int p[MAXN + 2];
int twoInv[MAXN + 1];

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

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int choose(int n, int k)
{
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = twoInv[0] = 1;
    int two = modinv(2);
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        twoInv[i] = (int) ((long long) twoInv[i - 1] * two % MOD);
    }
    invFac[MAXN] = modinv(fac[MAXN]);
    for (int i = MAXN - 1; i >= 0; i--)
    {
        invFac[i] = (int) ((long long) invFac[i + 1] * (i + 1) % MOD);
    }
    int n;
    long long maxt;
    cin >> n >> maxt;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    long long sum = 0;
    int ans = 0;
    int num = -1;
    int topk = -1;
    for (int i = 0; i < n; i++)
    {
        sum += t[i];
        if (sum > maxt)
            break;
        long long extra = maxt - sum;
        if (extra >= i + 1)
        {
            p[i + 1] = 1;
            continue;
        }
        if (num < 0)
        {
            num = 0;
            for (int j = 0; j <= extra; j++)
            {
                add(num, choose(i + 1, j));
            }
            topk = (int) extra;
        }
        else
        {
            num = (int) ((long long) num * 2 % MOD);
            add(num, MOD - choose(i, topk));
            for (int j = topk; j > extra; j--)
            {
                add(num, MOD - choose(i + 1, j));
            }
            topk = min(topk, (int) extra);
        }
        p[i + 1] = (int) ((long long) num * twoInv[i + 1] % MOD);
    }
    for (int i = 1; i <= n; i++)
    {
        int temp = (int) ((long long) (p[i] - p[i + 1] + MOD) % MOD);
        temp = (int) ((long long) temp * i % MOD);
        add(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}