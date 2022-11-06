#include <bits/stdc++.h>

using namespace std;

const int LOGN = 30;
int freq[LOGN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        fill(freq, freq + LOGN, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[__builtin_ctz(x)]++;
        }
        int ans = 0;
        while (n)
        {
            ans++;
            int cur = w;
            for (int i = LOGN - 1; i >= 0; i--)
            {
                while (freq[i] && cur >= (1 << i))
                {
                    n--;
                    freq[i]--;
                    cur -= 1 << i;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}