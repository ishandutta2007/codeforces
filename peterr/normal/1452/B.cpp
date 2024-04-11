#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int h = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            h = max(h, a[i]);
            sum += a[i];
        }
        long long ans = 0;
        if (sum > (long long) h * (n - 1))
        {
            int mod = sum % (n - 1);
            if (mod)
                ans = n - 1 - mod;
        }
        else if (sum < (long long) h * (n - 1))
        {
            ans = (long long) h * (n - 1) - sum;
        }
        cout << ans << "\n";
    }
    return 0;
}