#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ind = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] != i)
                ind = i;
        }
        double ans = 1;
        for (int i = 0; i < m; i++)
        {
            int r;
            double p;
            cin >> r >> p;
            if (r >= ind)
            {
                ans *= (1 - p);
            }
        }
        if (ind == 0)
            cout << "1\n";
        else
        {
            cout << fixed << setprecision(7) << 1 - ans << "\n";
        }
    }
    return 0;
}