#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool ans = false;
        for (int i = 1; (long long) 2 * i * i <= n; i++)
        {
            if (n == 2 * i * i || n == (long long) 4 * i * i)
                ans = true;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}