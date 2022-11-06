#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int nxt[MAXN];
int freq[26];

int main()
{
    string s;
    int q;
    cin >> s >> q;
    int n = (int) s.length();
    for (int i = 0; i < 26; i++)
    {
        fill(freq, freq + 26, 0);
        int rt = 0;
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            int key = s[j] - 'a';
            if (key == i)
            {
                if (num >= 2)
                {
                    nxt[j] = rt;
                }
                else
                {
                    while (rt < n && num < 2)
                    {
                        int c = s[rt] - 'a';
                        if (c != i)
                        {
                            freq[c]++;
                            if (freq[c] == 1)
                                num++;
                        }
                        rt++;
                    }
                    nxt[j] = rt;
                }
            }
            freq[key]--;
            if (freq[key] == 0)
                num--;
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r)
            cout << "Yes" << "\n";
        else if (s[l] != s[r])
            cout << "Yes" << "\n";
        else
        {
            if (r < nxt[l])
                cout << "No" << "\n";
            else
                cout << "Yes" << "\n";
        }
    }
    return 0;
}