#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXS = 200000;
bool dp[MAXS];
int a[MAXN];

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int odd = -1;
    int twos = 1 << 20;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        twos = __gcd(twos, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] /= twos;
        sum += a[i];
        if (a[i] & 1)
            odd = i;
    }
    if (sum % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    if (!dp[sum / 2])
    {
        cout << "0\n";
        return 0;
    }
    cout << "1\n";
    cout << odd + 1 << "\n";
    return 0;
}