#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long cycle[MAXN];
long long cross[MAXN];
long long a[MAXN];
long long b[MAXN];
long long c[MAXN];

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
        fill(cycle, cycle + n, 0);
        fill(cross, cross + n, 0);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        long long ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                swap(a[i], b[i]);
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                cross[i] = b[i + 1] - a[i + 1];
                if (i > 0 && a[i + 1] != b[i + 1])
                {
                    cross[i] = max(cross[i], a[i + 1] - 1 + c[i] - b[i + 1] + 2 + cross[i - 1]);
                }
            }
            if (i)
                cycle[i] = max(cycle[i], 2 + cross[i - 1] + c[i] - 1);
            ans = max(ans, cycle[i]);
            //cout << "CROSS " << i << " " << cross[i] << endl;
            //cout << "CYCLE " << i << " " << cycle[i] << endl;
        }
        cout << ans << "\n";
    }
    return 0;
}