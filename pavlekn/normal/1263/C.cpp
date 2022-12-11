#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

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
        set<int> ans = {0};
        for (int i = 1; i * i <= n; ++i)
        {
            ans.insert(i);
            ans.insert(n / i);
        }
        cout << ans.size() << endl;
        for (auto el : ans)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}