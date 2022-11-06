#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        int ptr = 0;
        while (ptr < n)
        {
            int start = ptr;
            while (ptr + 1 < n && a[ptr + 1] > a[ptr])
                ptr++;
            int mn = a[start - 1];
            if (start != ptr)
                mn = min(mn, a[start]);
            if (a[ptr] > mn)
            {
                ans += a[ptr] - mn;
                ptr += 2;
            }
            else
            {
                ptr++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}