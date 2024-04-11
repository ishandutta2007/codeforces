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
        string s, t;
        cin >> s >> t;
        int n = (int) s.length();
        int m = (int) t.length();
        int l = n * m / __gcd(n, m);
        bool valid = true;
        vector<char> v;
        for (int i = 0; i < l; i++)
        {
            v.push_back(s[i % n]);
            if (s[i % n] != t[i % m])
                valid = false;
        }
        if (valid)
        {
            for (char ch : v)
                cout << ch;
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}