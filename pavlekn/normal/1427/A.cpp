#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 0)
        {
            cout << "NO" << endl;
        }
        else if (sum < 0)
        {
            sort(a.begin(), a.end());
            cout << "YES" << endl;
            for (auto el : a)
            {
                cout << el << " ";
            }
            cout << endl;
        }
        else
        {
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
            cout << "YES" << endl;
            for (auto el : a)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
    return 0;
}