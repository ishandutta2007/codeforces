#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool first = true;
        bool ans = true;
        string target = "2020";
        for (int i = 0; i < 4; i++)
        {
            if (first)
            {
                if (s[i] != target[i])
                    first = false;
            }
            if (!first)
            {
                if (target[i] != s[n + i - 4])
                    ans = false;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}