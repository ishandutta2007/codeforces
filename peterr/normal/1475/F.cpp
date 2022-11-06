#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
string a[MAXN];
string b[MAXN];

char flip(char c)
{
    if (c == '0')
        return '1';
    return '0';
}

bool check(int n)
{
    for (int i = 1; i < n; i++)
    {
        char key = a[i][0];
        if (a[0][0] == '1')
            key = flip(key);
        for (int j = 1; j < n; j++)
        {
            char key2 = a[i][j];
            if (a[0][j] == '1')
                key2 = flip(key2);
            if (key != key2)
                return false;
        }
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
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (b[i][j] == '1')
                    a[i][j] = (a[i][j] == '0' ? '1' : '0');
        bool ans = check(n);
        for (int i = 0; i < n; i++)
            a[0][i] = (a[0][i] == '0' ? '1' : '0');
        ans = ans || check(n);
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}