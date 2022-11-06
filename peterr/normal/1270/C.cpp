#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long s = 0;
        long long xr = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s += x;
            xr ^= x;
        }
        cout << 2 << endl;
        cout << xr << " " << xr + s << endl;
    }
    return 0;
}