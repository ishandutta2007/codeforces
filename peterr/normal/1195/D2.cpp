#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1E5;
int arr[MAXN];
int length[11];
int sum[11];

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
        length[to_string(arr[i]).length()]++;
    }
    sum[0] = length[0];
    for (int i = 1; i < 11; i++)
    {
        sum[i] = length[i] + sum[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curLen = (int) to_string(arr[i]).length();
        int freq = n - sum[curLen - 1];
        long long num = 0;
        for (int j = 0; j < 10; j++)
        {
            int digit = (int) (arr[i] / (int) pow(10, j) % 10);
            int add = (int) ((long long) digit * modpow(10, 2 * j) % MOD);
            num = ((long long) num + add) % MOD;
        }
        ans = (ans + num * freq % MOD) % MOD;
        num = 0;
        for (int j = 0; j < 10; j++)
        {
            int digit = (int) (arr[i] / (int) pow(10, j) % 10);
            int add = (int) ((long long) digit * modpow(10, 2 * j + 1) % MOD);
            num = ((long long) num + add) % MOD;
        }
        ans = (ans + num * freq % MOD) % MOD;
        for (int j = 1; j < curLen; j++)
        {
            if (length[j] == 0)
                continue;
            num = 0;
            for (int k = 0; k < 10; k++)
            {
                int digit = (int) (arr[i] / (int) pow(10, k) % 10);
                int add;
                if (k <= j)
                    add = (int) ((long long) digit * modpow(10, 2 * k) % MOD);
                else
                    add = (int) ((long long) digit * modpow(10, k + j) % MOD);
                num = ((long long) num + add) % MOD;
            }
            ans = (ans + num * length[j] % MOD) % MOD;
            num = 0;
            for (int k = 0; k < 10; k++)
            {
                int digit = (int) (arr[i] / (int) pow(10, k) % 10);
                int add;
                if (k < j)
                    add = (int) ((long long) digit * modpow(10, 2 * k + 1) % MOD);
                else
                    add = (int) ((long long) digit * modpow(10, k + j) % MOD);
                num = ((long long) num + add) % MOD;
            }
            ans = (ans + num * length[j] % MOD) % MOD;
        }
    }
    cout << ans;

    return 0;
}