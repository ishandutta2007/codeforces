#include <bits/stdc++.h>

using namespace std;

int freq[64];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int m;
        cin >> n >> m;
        long long sum = 0;
        fill(freq, freq + 64, 0);
        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            sum += a;
            freq[__builtin_ctz(a)]++;
        }
        if (sum < n)
        {
            cout << -1 << "\n";
        }
        else
        {
            long long ans = 0;
            for (int i = 0; i < 63; i++)
            {
                if (n & (1LL << i))
                {
                    if (freq[i])
                    {
                        freq[i]--;
                    }
                    else
                    {
                        int ptr = i;
                        while (freq[ptr] == 0)
                        {
                            ptr++;
                            ans++;
                        }
                        freq[ptr]--;
                        for (int j = ptr - 1; j >= i; j--)
                        {
                            freq[j]++;
                        }
                    }
                }
                freq[i + 1] += freq[i] / 2;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}