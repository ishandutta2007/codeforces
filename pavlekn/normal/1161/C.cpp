#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    int mn = INF;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == mn)
        {
            ++cnt;
        }
        if (a[i] < mn)
        {
            mn = a[i];
            cnt = 1;
        }
    }
    if (cnt > n / 2)
    {
        cout << "Bob" << endl;
        return 0;
    }
    cout << "Alice" << endl;
    return 0;
}