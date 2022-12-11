#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    srand(clock());
    int n, k;
    cin >> n >> k;
    int l = 1;
    int r = n;
    string ans;
    while (true)
    {
        if ((r - l) < 50)
        {
            int x = l + rand() % (r - l + 1);
            cout << x << " " << x << endl;
            cin >> ans;
            if (ans == "Yes")
            {
                break;
            }
            else
            {
                l = max(1ll * 1, l - k);
                r = min(n, r + k);
            }
        }
        else
        {
            int m = (l + r) / 2;
            cout << l << " " << m << endl;
            cin >> ans;
            if (ans == "Yes")
            {
                l = max(1ll * 1, l - k);
                r = min(n, m + k);
            }
            else
            {
                l = max(1ll * 1, m - k);
                r = min(n, r + k);
            }
        }
    }
    return 0;
}