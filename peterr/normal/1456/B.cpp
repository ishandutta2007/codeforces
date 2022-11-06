#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int LOG = 35;
int a[MAXN + 1];
int pref[MAXN + 1];
int freq[LOG];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[__builtin_clz(a[i])]++;
    }
    for (int i = 0; i < LOG; i++)
    {
        if (freq[i] >= 3)
        {
            cout << "1\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] ^ a[i];
    }
    int ans = MAXN;
    for (int l1 = 1; l1 <= n; l1++)
    {
        for (int r1 = l1; r1 <= n; r1++)
        {
            for (int l2 = r1 + 1; l2 <= n; l2++)
            {
                for (int r2 = l2; r2 <= n; r2++)
                {
                    int x = pref[r1] ^ pref[l1 - 1];
                    int y = pref[r2] ^ pref[l2 - 1];
                    if (x > y)
                        ans = min(ans, (r1 - l1) + (r2 - l2));
                }
            }
        }
    }
    if (ans == MAXN)
        ans = -1;
    cout << ans << "\n";
    return 0;
}