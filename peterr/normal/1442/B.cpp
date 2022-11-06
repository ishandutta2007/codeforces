#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];
int pos[MAXN + 1];
bool special[MAXN + 1];

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
        fill(pos + 1, pos + n + 1, -1);
        fill(special + 1, special + n + 1, false);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
            special[b[i]] = true;
        }
        int ans = 1;
        set<int> active;
        for (int i = 0; i < n; i++)
            active.insert(i);
        for (int i = 0; i < k; i++)
        {
            int cur = b[i];
            if (pos[cur] == -1)
            {
                ans = 0;
                break;
            }
            int cnt = 0;
            auto it = active.upper_bound(pos[cur]);
            if (it != active.end())
            {
                int ind = *it;
                if (!special[a[ind]])
                    cnt++;
            }
            it = active.find(pos[cur]);
            if (it != active.begin())
            {
                it--;
                int ind = *it;
                if (!special[a[ind]])
                    cnt++;
            }
            active.erase(pos[cur]);
            ans = (int) ((long long) ans * cnt % MOD);
        }
        cout << ans << "\n";
    }
    return 0;
}