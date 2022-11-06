#include <bits/stdc++.h>

using namespace std;

const int SQRT = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        long long ans = 0;
        int cur = 1;
        while (cur <= y)
        {
            int num = x / (cur + 1);
            if (!num)
                break;
            int nxt = min(x / num, y + 1);
            ans += num * (nxt - cur);
            cur = nxt;
        }
        for (int i = 1; i <= min(y, SQRT); i++)
        {
            ans -= x / (i + 1);
            ans += min(i - 1, x / (i + 1));
        }
        cout << ans << "\n";
    }
    return 0;
}