#include <iostream>

using namespace std;

const int MAXN = 1E5;
long long a[MAXN];
long long dp[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0] = a[0] * (n - a[0] + 1);
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i-1];
        if (a[i] > a[i-1])
        {
            dp[i] += (a[i] - a[i-1]) * (n - a[i] + 1);
        }
        else if (a[i] < a[i-1])
        {
            dp[i] += a[i] * (a[i-1] - a[i]);
        }
    }
    cout << dp[n-1];
    return 0;
}