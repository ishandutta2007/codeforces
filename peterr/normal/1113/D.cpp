#include <iostream>

using namespace std;

string s;

bool isPalindrome(int l, int r)
{
    if (l >= r)
        return true;
    for (int i = 0; i <= (r - l) / 2; i++)
    {
        if (s[l+i] != s[r-i])
            return false;
    }
    return true;
}

int solve()
{
    if (s.length() == 1)
        return -1;

    int mid = s.length() / 2;
    bool same = true;
    for (int i = 0; i < mid; i++)
    {
        if (s[i] != s[0])
            same = false;
    }
    if (same)
        return -1;
    if (s.length() % 2 == 1)
    {
        return 2;
    }
    else
    {
        for (int i = 0; i < mid; i++)
        {
            if (isPalindrome(0, i))
                continue;
            bool good = true;
            for (int j = 0; j <= i; j++)
            {
                if (s[j] != s[i * 2 + 1 - j])
                    good = false;
            }
            if (good && isPalindrome(i * 2 + 2, s.length() - 1))
                return 1;
        }
        return 2;
    }
}

int main()
{
    cin >> s;
    int sol = solve();
    if (sol == -1)
        cout << "Impossible";
    else
        cout << sol;
    return 0;
}