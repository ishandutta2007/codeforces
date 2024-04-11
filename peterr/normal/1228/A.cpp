#include <bits/stdc++.h>

using namespace std;

bool check(int x)
{
    string s = to_string(x);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
                return false;
        }
    }
    return true;
}

int main()
{
    int l, r;
    cin >> l >> r;
    int ans = -1;
    for (int i = l; i <= r; i++)
    {
        if (check(i))
        {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}