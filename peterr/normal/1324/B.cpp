#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int a[MAXN];
int used[MAXN + 1];

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
        fill(used + 1, used + n + 1, MAXN + 5);
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (used[x] <= i - 2)
                ans = true;
            used[x] = min(used[x], i);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}