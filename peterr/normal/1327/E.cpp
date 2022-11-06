#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 998244353;
int ans[MAXN + 1];
int tenpow[MAXN + 1];

int main()
{
    tenpow[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        tenpow[i] = (int) (((long long) 10 * tenpow[i - 1]) % MOD);
    }
    int n;
    cin >> n;
    ans[n] = 10;
    for (int i = 1; i < n; i++)
    {
        ans[i] = (int) (((long long) 18 * tenpow[n - i]) % MOD);
        int temp = (int) (((long long) 81 * tenpow[n - i - 1]) % MOD);
        temp = (int) (((long long) (n - i - 1) * temp) % MOD);
        ans[i] += temp;
        if (ans[i] >= MOD)
            ans[i] -= MOD;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}