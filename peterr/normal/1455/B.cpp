#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int ans = 0;
        int cur = 0;
        int cnt = 1;
        while (cur < x)
        {
            cur += cnt;
            cnt++;
            ans++;
        }
        if (cur - x == 1)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}