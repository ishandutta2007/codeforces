#include <bits/stdc++.h>

using namespace std;

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
        map<pair<int, int>, int> freq;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            int dx = u - x;
            int dy = v - y;
            if (dx == 0)
                dy /= abs(dy);
            else if (dy == 0)
                dx /= abs(dx);
            else
            {
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
            }
            ans += freq[{-dx, -dy}];
            freq[{dx, dy}]++;
        }
        cout << ans << "\n";
    }
    return 0;
}