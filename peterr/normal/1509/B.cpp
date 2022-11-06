#include <bits/stdc++.h>

using namespace std;

bool check(string &s)
{
    int bal = 0;
    for (char ch : s)
    {
        if (ch == 'T')
            bal++;
        else
            bal--;
        if (bal < 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int cnt0 = 0;
        int cnt1 = 0;
        for (char ch : s)
        {
            cnt0 += ch == 'T';
            cnt1 += ch == 'M';
        }
        if (cnt1 * 2 != cnt0)
        {
            cout << "NO\n";
            continue;
        }
        bool ans = check(s);
        reverse(s.begin(), s.end());
        ans = ans && check(s);
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}