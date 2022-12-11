#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = b[i] + mx;
        cout << x << " ";
        mx = max(mx, x);
    }
    cout << endl;
    return 0;
}