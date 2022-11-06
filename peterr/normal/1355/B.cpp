#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int e[MAXN];

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
            cin >> e[i];
        sort(e, e + n);
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur++;
            if (cur >= e[i])
            {
                ans++;
                cur = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}