#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e12 + 11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int L = -1;
    int R = INF;
    int s;
    while (R - L > 1)
    {
        int MED = (L + R) / 2ll;
        s = 0;
        for (int i = 0; i < n; ++i)
        {
            s += (MED + i);
        }
        if (s >= sum)
        {
            R = MED;
        }
        else
        {
            L = MED;
        }
    }
    s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += (R + i);
    }
    for (int i = 0; i < n; ++i)
    {
        int cur = (R + i);
        if ((s - sum) + i >= n)
        {
            --cur;
        }
        cout << cur << " ";
    }
    cout << endl;
    return 0;
}