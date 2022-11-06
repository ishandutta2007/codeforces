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
        int n;
        cin >> n;
        int mn = 101;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x < mn)
            {
                mn = x;
                cnt = 1;
            }
            else if (x == mn)
                cnt++;
        }
        cout << n - cnt << "\n";
    }
    return 0;
}