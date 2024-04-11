#include <bits/stdc++.h>

using namespace std;

const int MAXL = 1E5;
int ans[MAXL];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long l, r;
        cin >> n >> l >> r;
        if (n == 2)
        {
            ans[0] = 1;
            ans[1] = 2;
            ans[2] = 1;
            for (long long i = l; i <= r; i++)
            {
                cout << ans[i - 1] << " ";
            }
            cout << "\n";
            continue;
        }
        int ptr = 0;
        for (long long i = l; i <= min(r, 2LL * n - 2); i++)
        {
            if (i % 2 != 0)
                ans[ptr++] = 1;
            else
                ans[ptr++] = i / 2 + 1;
        }
        long long start = 2 * (n - 2) + 3;
        for (int i = 2; i <= n - 1; i++)
        {
            int par = start & 1;
            long long end = start + (long long) 2 * (n - i - 1) + 1;
            for (long long j = max(start, l); j <= min(r, end); j++)
            {
                if (j & 1 == par)
                    ans[ptr++] = i;
                else
                    ans[ptr++] = i + (j - start + 1) / 2;
            }
            start = end + 1;
        }
        if (r == (long long) n * (n - 1) + 1)
            ans[ptr++] = 1;
        for (int i = 0; i < r - l + 1; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}