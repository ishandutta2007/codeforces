#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
long long a[MAXN];
long long b[MAXN];
long long work[MAXN];

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
        if (n == 1)
        {
            cout << a[0] << "\n";
            continue;
        }
        long long ans = 1E18;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            work[(i + 1) % n] = max(0LL, a[(i + 1) % n] - b[i]);
            sum += work[(i + 1) % n];
        }
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, sum - work[i] + a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}