#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];
int pos[MAXN + 1];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        long long ans = m;
        int ptr = -1;
        for (int i = 0; i < m; i++)
        {
            int next = b[i];
            if (pos[next] > ptr)
            {
                ans += 2 * (pos[next] - i);
                ptr = pos[next];
            }
        }
        cout << ans << endl;
    }
    return 0;
}