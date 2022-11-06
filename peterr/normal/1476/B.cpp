#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i)
            {
                ans = max(ans, ((long long) 100 * x + k - 1) / k - sum);
            }
            sum += x;
        }
        cout << ans << "\n";
    }
    return 0;
}