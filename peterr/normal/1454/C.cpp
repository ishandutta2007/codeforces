#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int freq[MAXN + 1];
bool seen[MAXN + 1];
int a[MAXN];

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
        fill(freq + 1, freq + n + 1, 0);
        fill(seen + 1, seen + n + 1, false);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            seen[a[i]] = true;
        }
        freq[a[0]]++;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                freq[a[i]]++;
        }
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        freq[a[0]]--;
        freq[a[n - 1]]--;
        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            if (!seen[i])
                continue;
            ans = min(ans, freq[i] + 1);
        }
        ans = max(0, ans);
        cout << ans << "\n";
    }
    return 0;
}