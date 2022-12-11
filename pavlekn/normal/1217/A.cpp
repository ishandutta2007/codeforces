#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int l = -1;
        int r = c + 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (a + m > b + c - m)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        cout << c - r + 1 << endl;
    }
    return 0;
}