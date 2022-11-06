#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<long long, int> seen;
    seen[0] = -1;
    long long pre = 0;
    long long ans = (long long) n * (n + 1) / 2;
    int left = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pre += x;
        if (seen.count(pre))
        {
            int bound = seen[pre] + 1;
            if (bound > left)
            {
                ans -= (long long) (bound - left) * (n - i);
                left = bound;
            }
        }
        seen[pre] = i;
    }
    cout << ans << endl;
    return 0;
}