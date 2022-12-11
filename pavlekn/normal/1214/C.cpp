#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

bool check(string s)
{
    int n = s.size();
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            ++cur;
        }
        else
        {
            --cur;
        }
        if (cur < 0)
        {
            return false;
        }
    }
    if (cur == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    string u = s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == ')')
        {
            t = "";
            for (int j = 0; j < i; ++j)
            {
                t.push_back(s[j]);
            }
            for (int j = i + 1; j < n; ++j)
            {
                t.push_back(s[j]);
            }
            t.push_back(')');
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '(')
        {
            u = "(";
            for (int j = 0; j < i; ++j)
            {
                u.push_back(s[j]);
            }
            for (int j = i + 1; j < n; ++j)
            {
                u.push_back(s[j]);
            }
            break;
        }
    }
    if (check(t) || check(u))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}