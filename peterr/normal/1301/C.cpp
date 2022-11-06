#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int comps = min(m + 1, (n + 1) / 2);
        int zeros = n - m;
        int compZ = (zeros + comps - 1) / comps;
        int big = zeros % comps;
        if (big == 0)
            big = comps;
        int small = comps - big;
        long long ex = (long long) (compZ + 1) * compZ / 2 * big;
        ex += (long long) (compZ - 1) * compZ / 2 * small;
        long long ans = (long long) (n + 1) * n / 2 - ex;
        cout << ans << endl;
    }
    return 0;
}