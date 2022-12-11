#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            if (i % 2)
            {
                cout << a[i - 1] << " ";
            }
            else
            {
                cout << -(a[i + 1]) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}