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
        if (n % 2 == 0)
        {
            cout << (k - 1) % n + 1 << "\n";
        }
        else
        {
            int steps = n / 2;
            int cycles = (k - 1) / steps;
            int rem = (k - 1) % steps;
            int ans = (int) ((long long) (n + 1) / 2 * cycles % n);
            ans = (ans + rem) % n;
            cout << ans + 1 << "\n";
        }
    }
    return 0;
}