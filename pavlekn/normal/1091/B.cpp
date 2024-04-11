#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> a(n);
    vector<int> b(n);
    int max_x = -INF;
    int max_y = -INF;
    int min_x = INF;
    int min_y = INF;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        max_x = max(x[i], max_x);
        max_y = max(y[i], max_y);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        min_x = min(a[i], min_x);
        min_y = min(b[i], min_y);
    }
    cout << max_x + min_x << " " << max_y + min_y << endl;
    return 0;
}