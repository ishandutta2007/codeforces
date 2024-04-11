#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
int pref[MAXN + 1];

bool check(int n, int k, int cutoff)
{
    int sum = 0;
    int lowEven = n + 10;
    int lowOdd = n + 10;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= cutoff)
            sum++;
        else
            sum--;
        pref[i] = sum;
        if (i - k >= 0)
        {
            if ((i - k) & 1)
                lowOdd = min(lowOdd, pref[i - k]);
            else
                lowEven = min(lowEven, pref[i - k]);
        }
        if (i & 1)
        {
            if (sum - lowOdd >= 2 || sum - lowEven >= 1)
                return true;
        }
        else
        {
            if (sum - lowEven >= 2 || sum - lowOdd >= 1)
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 1;
    for (int jump = n; jump; jump >>= 1)
    {
        while (ans + jump <= n && check(n, k, ans + jump))
            ans += jump;
    }
    cout << ans << "\n";
    return 0;
}