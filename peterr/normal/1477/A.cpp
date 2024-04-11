#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
long long a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long g = a[1] - a[0];
        for (int i = 2; i < n; i++)
            g = __gcd(g, a[i] - a[i - 1]);
        if (abs(k - a[0]) % g == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}