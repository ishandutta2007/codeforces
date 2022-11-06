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
        int n, x;
        cin >> n >> x;
        long long sum = 0;
        long long big = 0;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            sum += y;
            big += (y + x - 1) / x;
        }
        cout << (sum + x - 1) / x << " " << big << "\n";
    }
    return 0;
}