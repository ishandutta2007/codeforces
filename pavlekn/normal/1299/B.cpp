#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    int k = n / 2;
    for (int i = 0; i < k; ++i)
    {
        if (x[i + 1] - x[i] != -x[(i + k + 1) % n] + x[i + k] || y[i + 1] - y[i] != -y[(i + k + 1) % n] + y[i + k])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}