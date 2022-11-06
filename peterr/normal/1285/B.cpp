#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long pre[MAXN + 1];

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
        long long y = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> pre[i];
            y += pre[i];
            pre[i] += pre[i - 1];
        }
        long long a = -1E15;
        long long big = pre[n];
        for (int i = n; i >= 2; i--)
        {
            big = max(big, pre[i]);
            a = max(a, big - pre[i - 1]);
        }
        for (int i = 1; i <= n - 1; i++)
            a = max(a, pre[i]);
        if (y > a)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}