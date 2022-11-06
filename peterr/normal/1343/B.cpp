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
        if ((n / 2) % 2 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            long long sum = 0;
            for (int i = 0; i < n / 2; i++)
            {
                cout << (i + 1) * 2 << " ";
                sum += (i + 1) * 2;
            }
            for (int i = 0; i < n / 2 - 1; i++)
            {
                cout << 2 * i + 1 << " ";
                sum -= 2 * i + 1;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}