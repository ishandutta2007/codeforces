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
        if (n % 2 != k % 2)
            cout << "NO" << "\n";
        else
        {
            bool ans = true;
            long long cur = 0;
            for (int i = 0; i < k; i++)
            {
                cur += 2 * i + 1;
                if (cur > n)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}