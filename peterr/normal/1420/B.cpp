#include <bits/stdc++.h>

using namespace std;

int freq[40];

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
        fill(freq, freq + 40, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[__builtin_clz(x)]++;
        }
        long long ans = 0;
        for (int i = 0; i < 40; i++)
        {
            if (freq[i] == 0)
                continue;
            ans += (long long) freq[i] * (freq[i] - 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}