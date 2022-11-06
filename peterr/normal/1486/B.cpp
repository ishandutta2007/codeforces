#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];
int b[MAXN];

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
            cin >> a[i] >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        if (n & 1)
        {
            cout << "1\n";
        }
        else
        {
            long long ans = (long long) (a[n/2] - a[n/2-1]+1) * (b[n/2] - b[n/2-1]+1);
            cout << ans << "\n";
        }
    }
    return 0;
}