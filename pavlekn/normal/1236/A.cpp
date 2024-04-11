#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = min(b, c / 2);
        b -= ans;
        c -= 2 * ans;
        int ans2 = min(a, b / 2);
        a -= ans2;
        b -= 2 * ans2;
        cout << 3 * (ans + ans2) << endl;
    }
    return 0;
}