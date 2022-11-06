#include <bits/stdc++.h>

using namespace std;

int freq1[26];
int freq2[26];

void computeFreq(const string &s, int freq[26])
{
    fill(freq, freq + 26, 0);
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }
}

void removeChar(string &s, int key)
{
    stringstream ss;
    for (char ch : s)
    {
        if (ch - 'a' == key)
            continue;
        ss << ch;
    }
    s = ss.str();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans = "";
        while (!s.empty())
        {
            computeFreq(s, freq1);
            for (int i = 25; i >= 0; i--)
            {
                if (!freq1[i])
                    continue;
                int pos = 0;
                while (s[pos] - 'a' != i)
                    pos++;
                if (pos == 0)
                {
                    removeChar(s, i);
                    ans = ans + (char) ('a' + i);
                    break;
                }
                else
                {
                    computeFreq(s.substr(0, pos), freq2);
                    bool valid = true;
                    for (int j = 0; j < 26; j++)
                    {
                        if (freq1[j] > 0 && freq2[j] == freq1[j])
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                    {
                        s = s.substr(pos + 1);
                        removeChar(s, i);
                        ans = ans + (char) ('a' + i);
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}