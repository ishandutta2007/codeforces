#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << n + 1 << endl;
    for (int i = 0; i < n; ++i)
    {
        int delta = (((2000 - i - 1) - a[n - i - 1]) % 2000 + 2000) % 2000;
        cout << 1 << " " << n - i << " " << delta << endl;
        for (int j = 0; j <= n - i - 1; ++j)
        {
            a[j] += delta;
        }
    }
    cout << 2 << " " << n << " " << 2000 << endl;
    return 0;
}