#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int b, g;
    cin >> b >> g;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (i <= b && n - i <= g)
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}