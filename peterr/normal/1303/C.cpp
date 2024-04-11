#include <bits/stdc++.h>

using namespace std;

int ans[100];
bool used[26];
int loc[26];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        fill(ans, ans + 100, -1);
        fill(used, used + 26, false);
        int ptr = 50;
        ans[ptr] = s[0] - 'a';
        used[s[0] - 'a'] = true;
        loc[s[0] - 'a'] = ptr;
        bool valid = true;
        int left = ptr;
        for (int i = 1; i < (int) s.length(); i++)
        {
            int key = s[i] - 'a';
            if (used[key])
            {
                if (loc[key] == ptr - 1 || loc[key] == ptr + 1)
                {
                    ptr = loc[key];
                }
                else
                    valid = false;
            }
            else
            {
                if (ans[ptr + 1] == -1)
                {
                    ptr++;
                    ans[ptr] = key;
                    used[key] = true;
                    loc[key] = ptr;
                }
                else if (ans[ptr - 1] == -1)
                {
                    ptr--;
                    ans[ptr] = key;
                    used[key] = true;
                    loc[key] = ptr;
                }
                else
                    valid = false;
            }
            left = min(left, ptr);
        }
        if (valid)
        {
            cout << "YES" << endl;
            stringstream ss;
            while (ans[left] != -1)
            {
                ss << (char) ('a' + ans[left++]);
            }
            for (int i = 0; i < 26; i++)
                if (!used[i])
                    ss << (char) ('a' + i);
            cout << ss.str() << endl;

        }
        else
            cout << "NO" << endl;
    }
    return 0;
}