#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cout << "? ";
    for (int i = 0; i < 100; ++i)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    int ans = 0;
    ans += ((res >> 7) << 7);
    cout << "? ";
    for (int i = 0; i < 100; ++i)
    {
        cout << 128 * i << " ";
    }
    cout << endl;
    cin >> res;
    ans += (res % 128);
    cout << "! " << ans << endl;
    return 0;
}