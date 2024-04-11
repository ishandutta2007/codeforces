#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (1 / (long double) i);
    }
    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}