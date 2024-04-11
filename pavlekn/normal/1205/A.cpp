#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> a(2 * n);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                a[i - 1] = 2 * i - 1;
                a[i - 1 + n] = 2 * i;
            }
            else
            {
                a[i - 1] = 2 * i;
                a[i - 1 + n] = 2 * i - 1;
            }
        }
        cout << "YES" << endl;
        for (auto el : a)
        {
            cout << el << " ";
        }
    }
    return 0;
}