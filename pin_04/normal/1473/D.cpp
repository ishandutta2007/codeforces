#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int a[N];
int maxpre[N];
int maxsuf[N];
int minpre[N];
int minsuf[N];
int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n + 1; i++)
            a[i] = maxpre[i] = maxsuf[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            char c; cin >> c;
            a[i] += a[i - 1];
            if (c == '-')
                a[i]--;
            else
                a[i]++;
        }
        maxsuf[n + 1] = minsuf[n + 1] = a[n];

        for (int i = 1; i <= n; i++)
        {
            maxpre[i] = max(maxpre[i - 1], a[i]);
            minpre[i] = min(minpre[i - 1], a[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            maxsuf[i] = max(maxsuf[i + 1], a[i]);
            minsuf[i] = min(minsuf[i + 1], a[i]);
        }

        for (int i = 1; i <= m; i++)
        {
            int l,r;
            cin >> l >> r;
            int mx = max(maxpre[l - 1], maxsuf[r + 1] - (a[r] - a[l - 1]));
            int mn = min(minpre[l - 1], minsuf[r + 1] - (a[r] - a[l - 1]));
            cout << mx - mn + 1 << "\n";
        }
    }
    return 0;
}