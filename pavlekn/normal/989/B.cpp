#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    char a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = s[i];
    }
    int ans = 0;
    for (int i = 0; i < n - p; ++i)
    {
        if (a[i] != '.' && a[i + p] != '.' && a[i] != a[i + p])
        {
            ans = 1;
        }
        else if (a[i] == '.' && a[i + p] == '0')
        {
            ans = 1;
            a[i] = '1';
        }
        else if (a[i] == '.' && a[i + p] == '1')
        {
            ans = 1;
            a[i] = '0';
        }
        else if (a[i] == '0' && a[i + p] == '.')
        {
            ans = 1;
            a[i + p] = '1';
        }
        else if (a[i] == '1' && a[i + p] == '.')
        {
            ans = 1;
            a[i + p] = '0';
        }
        else if (a[i] == '.' && a[i + p] == '.')
        {
            ans = 1;
            a[i] = '0';
            a[i + p] = '1';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '.')
        {
            a[i] = '0';
        }
    }
    if (ans == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
        }
    }
}