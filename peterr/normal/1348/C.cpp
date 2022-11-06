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
        string s;
        cin >> n >> k >> s;
        fill(freq, freq + 26, 0);
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        if (k == n)
        {
            sort(s.begin(), s.end());
            cout << s[(int) s.length() - 1] << "\n";
        }
        else if (k == 1)
        {
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
        else
        {
            int p = 0;
            while (freq[p] == 0)
                p++;
            if (freq[p] < k)
            {
                sort(s.begin(), s.end());
                cout << s[k - 1] << "\n";
            }
            else
            {
                freq[p] -= k;
                int cnt = 0;
                stringstream ss;
                stringstream ss2;
                char c = 'a';
                ss << (char) ('a' + p);
                ss2 << (char) ('a' + p);
                int num = 0;
                while (p < 26)
                {
                    if (freq[p])
                        cnt++;
                    while (freq[p])
                    {
                        num++;
                        c = (char) ('a' + p);
                        freq[p]--;
                        ss << (char) ('a' + p);
                    }
                    p++;
                }
                if (cnt > 1)
                {
                    cout << ss.str() << "\n";
                }
                else if (cnt == 1)
                {
                    for (int i = 0; i < (num + k - 1) / k; i++)
                    {
                        ss2 << c;
                    }
                    cout << ss2.str() << "\n";
                }
            }
        }
    }
    return 0;
}