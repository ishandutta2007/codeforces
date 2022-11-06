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
        int ans = 0;
        int n;
        cin >> n;
        int sum = 0;
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            best = max(best, sum);
        }
        ans += best;
        int m;
        cin >> m;
        sum = best = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            sum += x;
            best = max(best, sum);
        }
        ans += best;
        cout << ans << "\n";
    }
    return 0;
}