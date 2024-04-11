#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        map<int, int> cnt;
        for (int i = 0; i < l; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 0; i < r; i++)
        {
            int x;
            cin >> x;
            if (cnt.count(x) && cnt[x] > 0)
            {
                n -= 2;
            }
            cnt[x]--;
        }
        int save = 0;
        if (l > r)
        {
            for (auto it : cnt)
            {
                if (it.second >= 2)
                    save += it.second / 2;
            }
        }
        else
        {
            for (auto it : cnt)
            {
                if (it.second <= -2)
                    save += -it.second / 2;
            }
        }
        int diff = abs(l - r) / 2;
        save = min(save, diff);
        int ans = diff - save + n / 2;
        cout << ans << "\n";
    }
    return 0;
}