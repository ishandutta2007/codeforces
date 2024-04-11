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
        string s, t, p;
        cin >> s >> t >> p;
        for (int i = 0; i < p.length(); i++)
        {
            freq[p[i] - 'a']++;
        }
        int i = 0, j = 0;
        bool valid = true;
        while (valid && j < t.length())
        {
            if (i < s.length() && s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                int key = t[j] - 'a';
                if (freq[key] > 0)
                {
                    freq[key]--;
                    j++;
                }
                else
                {
                    valid = false;
                }
            }
        }

        if (valid && j == t.length() && i == s.length())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        fill(freq, freq + 26, 0);
    }
    return 0;
}