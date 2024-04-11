#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int freq[MAXN + 1];

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        int total = 2;
        freq[a[0]]++;
        freq[a[n - 1]]++;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                ans++;
                freq[a[i]]++;
                freq[a[i + 1]]++;
                total += 2;
            }
        }
        int big = 1;
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] > freq[big])
                big = i;
        }
        int extra = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                continue;
            if (a[i] != big && a[i + 1] != big)
                extra += 2;
        }
        while (freq[big] > total / 2 + 1)
        {
            if (extra)
            {
                extra -= 2;
                total += 2;
                ans++;
            }
            else
            {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}