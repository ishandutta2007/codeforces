#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
pair<int, int> e[4 * MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ind = 0;
        for (int i = 0; i < n / 2; i++)
        {
            int x = a[i];
            int y = a[n - i - 1];
            e[ind++] = make_pair(min(x, y) + 1, -1);
            e[ind++] = make_pair(x + y, -1);
            e[ind++] = make_pair(x + y + 1, 1);
            e[ind++] = make_pair(max(x, y) + k + 1, 1);
        }
        sort(e, e + ind);
        int ptr = 0;
        int ans = n;
        int cur = n;
        while (ptr < ind)
        {
            int sum = e[ptr].first;
            cur += e[ptr].second;
            if (sum > 2 * k)
                break;
            ptr++;
            while (ptr < ind && e[ptr].first == sum)
            {
                cur += e[ptr].second;
                ptr++;
            }
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}