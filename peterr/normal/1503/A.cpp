#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
char a[MAXN];
char b[MAXN];

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
        int bal1 = 0;
        int bal2 = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        int ones = 0;
        int zeros = 0;
        for (char ch : s)
        {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }
        bool valid = ones % 2 == 0;
        for (int i = 0; i < (int) s.length(); i++)
        {
            if (s[i] == '1')
            {
                if (cnt1 < ones / 2)
                    a[i] = b[i] = '(';
                else
                    a[i] = b[i] = ')';
                cnt1++;
            }
            else
            {
                if (cnt0 & 1)
                    a[i] = '(', b[i] = ')';
                else
                    a[i] = ')', b[i] = '(';
                cnt0++;
            }
            if (a[i] == '(')
                bal1++;
            else
                bal1--;
            if (b[i] == '(')
                bal2++;
            else
                bal2--;
            if (bal2 < 0 || bal1 < 0)
                valid = false;
        }
        if (valid)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << a[i];
            cout << "\n";
            for (int i = 0; i < n; i++)
                cout << b[i];
            cout << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}