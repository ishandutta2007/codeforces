#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1E5;
int arr[MAXN];

int modpow(int b, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return b;
    long long res = modpow(b, p / 2);
    if (p % 2 == 0)
        return (int) (res * res % MOD);
    return (int) (((res * res % MOD) * b) % MOD);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long num = 0;
        for (int j = 0; j < 10; j++)
        {
            int digit = (int) (arr[i] / (int) pow(10, j) % 10);
            int add = (int) ((long long) digit * modpow(10, 2 * j) % MOD);
            num = ((long long) num + add) % MOD;
        }
        ans = (ans + num * n % MOD) % MOD;
        num = 0;
        for (int j = 0; j < 10; j++)
        {
            int digit = (int) (arr[i] / (int) pow(10, j) % 10);
            int add = (int) ((long long) digit * modpow(10, 2 * j + 1) % MOD);
            num = ((long long) num + add) % MOD;
        }
        ans = (ans + num * n % MOD) % MOD;
    }
    cout << ans;

    return 0;
}