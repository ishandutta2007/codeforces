#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
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
        string a, b;
        cin >> a >> b;
        fill(freq, freq + 26, 0);
        for (char c : a)
        {
            freq[c - 'a']++;
        }
        for (char c : b)
        {
            freq[c - 'a']--;
        }
        bool ans = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < 0 || freq[i] % k != 0)
            {
                ans = false;
                break;
            }
            if (i < 25)
                freq[i + 1] += freq[i];
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}