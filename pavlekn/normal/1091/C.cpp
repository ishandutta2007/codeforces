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
    set<int> ans;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans.insert((n - i + 2) * (n / i) / 2);
            ans.insert(((n - n / i + 2) * i) / 2);
        }
    }
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}