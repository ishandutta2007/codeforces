#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = false;
        int target = 0;
        for (int i = 0; i < n - 1; i++)
        {
            target ^= a[i];
            int cur = 0;
            bool found = false;
            for (int j = i + 1; j < n; j++)
            {
                cur ^= a[j];
                if (cur == target)
                    found = true;
            }
            if (cur == 0 || cur == target)
                ans = ans || found;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}