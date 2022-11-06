#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int ans = n - 1;
        for (int len = n; len >= 1; len--)
        {
            if (sum % len != 0)
                continue;
            int d = sum / len;
            int ptr = 0;
            bool valid = true;
            while (ptr < n)
            {
                int cur = 0;
                while (cur < d)
                    cur += a[ptr++];
                if (cur > d)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ans = n - len;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}