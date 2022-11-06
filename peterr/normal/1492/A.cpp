#include <bits/stdc++.h>

using namespace std;

long long solve(long long p, long long a)
{
    return (p + a - 1) / a * a - p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;
        long long ans = solve(p, a);
        ans = min(ans, solve(p, b));
        ans = min(ans, solve(p, c));
        cout << ans << "\n";
    }
    return 0;
}