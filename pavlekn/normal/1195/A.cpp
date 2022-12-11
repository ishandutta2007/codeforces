#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1);
    int m = (n + 1) / 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    for (int i = 0; i <= k; ++i)
    {
        if (a[i] % 2 == 1)
        {
            ++cnt;
        }
    }
    cout << n - cnt / 2 << endl;
}