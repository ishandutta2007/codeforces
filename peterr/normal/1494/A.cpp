#include <bits/stdc++.h>

using namespace std;

bool check(string &s, vector<int> vec)
{
    int bal = 0;
    for (char ch : s)
    {
        int key = ch - 'A';
        bal += vec[key];
        if (bal < 0)
            return false;
    }
    return bal == 0;
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
        bool ans = false;
        for (int i = -1; i <= 1; i += 2)
        {
            for (int j = -1; j <= 1; j += 2)
            {
                for (int k = -1; k <= 1; k += 2)
                {
                    ans = ans || check(s, {i, j, k});
                }
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}