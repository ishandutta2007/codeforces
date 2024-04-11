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
        cout << 3 * n << endl;
        for (int i = 0; i < n; i += 2)
        {
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
        }
    }
    return 0;
}