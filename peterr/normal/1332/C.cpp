#include <bits/stdc++.h>

using namespace std;

int freq[26];

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
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < k / 2; i++)
        {
            fill(freq, freq + 26, 0);
            int maxFreq = 0;
            for (int j = 0; j < n / k; j++)
            {
                int key = s[j * k + i] - 'a';
                freq[key]++;
                maxFreq = max(maxFreq, freq[key]);
                key = s[(j + 1) * k - (i + 1)] - 'a';
                freq[key]++;
                maxFreq = max(maxFreq, freq[key]);
            }
            ans += 2 * n / k - maxFreq;
        }
        if (k % 2 != 0)
        {
            fill(freq, freq + 26, 0);
            int maxFreq = 0;
            for (int j = 0; j < n / k; j++)
            {
                int key = s[j * k + k / 2] - 'a';
                freq[key]++;
                maxFreq = max(maxFreq, freq[key]);
            }
            ans += n / k - maxFreq;
        }
        cout << ans << "\n";
    }
    return 0;
}