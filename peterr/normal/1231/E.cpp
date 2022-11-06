#include <bits/stdc++.h>

using namespace std;

int freq[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        fill(freq, freq + 26, 0);
        int n;
        string s, t;
        cin >> n >> s >> t;
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        bool poss = true;
        for (int j = 0; j < n; j++)
        {
            if (--freq[t[j] - 'a'] < 0)
                poss = false;
        }
        if (!poss)
        {
            cout << "-1\n";
            continue;
        }
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            int p = i;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == t[p])
                {
                    p++;
                }
            }
            ans = min(ans, n - (p - i));
        }
        cout << ans << "\n";
    }
    return 0;
}