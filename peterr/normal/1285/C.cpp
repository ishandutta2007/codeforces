#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    pair<long long, long long> ans = make_pair(1, x);
    for (int i = 1; (long long) i * i <= x; i++)
    {
        if (x % i == 0)
        {
            for (int g = 1; g * g <= i; g++)
            {
                if (g * x / i > x)
                    break;
                if (i % g != 0)
                    continue;
                if (g * x % i == 0)
                {
                    long long cand = g * x / i;
                    if (__gcd((long long) i, cand) == g && x % cand == 0 && max(cand, (long long) i) < max(ans.first, ans.second))
                        ans = make_pair(cand, (long long) i);
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}