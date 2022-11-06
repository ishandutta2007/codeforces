#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        set<char> seen;
        int ptr = 0;
        bool ans = true;
        while (ptr < n)
        {
            char ch = s[ptr];
            if (seen.count(ch))
                ans = false;
            seen.insert(ch);
            while (ptr < n && s[ptr] == ch)
                ptr++;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}