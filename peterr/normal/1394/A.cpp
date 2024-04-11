#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
long long pref[MAXN];
long long suff[MAXN];

int main()
{
    int n, d, m;
    cin >> n >> d >> m;
    int bigger = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
            bigger++;
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
            pref[i] = pref[i - 1] + a[i];
        else
            pref[i] = a[i];
    }
    if (bigger == 0)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            ans += a[i];
        cout << ans << "\n";
        return 0;
    }
    long long lowSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= m)
            lowSum += a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            suff[i] = a[i];
        else
            suff[i] = a[i] + suff[i + 1];
    }
    int atLeast = (n + d) / (d + 1);
    for (int i = 1; i <= min(bigger, atLeast); i++)
    {
        int minShadow = max((i - 1) * d, bigger - i);
        int maxShadow = min(i * d, n - i);
        if (minShadow > maxShadow)
            continue;
        long long temp = 0;
        if (minShadow - (bigger - i) - 1 >= 0)
            temp = suff[n - i] + lowSum - pref[minShadow - (bigger - i) - 1];
        else
            temp = suff[n - i] + lowSum;
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}