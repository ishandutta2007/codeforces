#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int d[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        int ptr = 0;
        int prev = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > prev)
            {
                prev = a[i];
                d[i] = d[ptr] + 1;
            }
            else
            {
                prev = a[i];
                ptr++;
                d[i] = d[ptr] + 1;
            }
            ans = max(ans, d[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}