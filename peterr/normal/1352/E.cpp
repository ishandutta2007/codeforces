#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8000;
int a[MAXN];
int freq[MAXN + 1];

int main()
{
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
            freq[a[i]]++;
        }
        for (int i = 1; i < n; i++)
            a[i] = a[i - 1] + a[i];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int cur = a[i];
            if (cur <= n)
            {
                ans += freq[cur];
                freq[cur] = 0;
            }
            for (int j = 0; j < i - 1; j++)
            {
                if (cur - a[j] <= n)
                {
                    ans += freq[cur - a[j]];
                    freq[cur - a[j]] = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}