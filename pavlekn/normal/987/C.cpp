#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s1, s2;
    int n, k, m, x;
    cin >> n;
    vector<int> a = {};
    vector<int> b = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b.push_back(x);
    }
    int INF = 1000000000;
    int ans = INF;
    for (int j = 1; j < n - 1; ++j)
    {
        s1 = INF;
        s2 = INF;
        for (int i = 0; i < j; ++i)
        {
            if (a[i] < a[j])
            {
                s1 = min(s1, b[i]);
            }
        }
        for (int k = j + 1; k < n; ++k)
        {
            if (a[j] < a[k])
            {
                s2 = min(s2, b[k]);
            }
        }
        ans = min(ans, b[j] + s1 + s2);
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}