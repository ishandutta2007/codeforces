#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
string s;

void upd(int& curx, int& cury, char c)
{
    if (c == 'U')
        cury++;
    else if (c == 'D')
        cury--;
    else if (c == 'R')
        curx++;
    else
        curx--;
}

bool check(int x, int y, int k, int n)
{
    int index = k;
    int curx = 0, cury = 0;
    for (int i = index; i < n; i++)
    {
        upd(curx, cury, s[i]);
    }
    while (index <= n)
    {
        if ((long long) abs(curx - x) + (long long) abs(cury - y) <= k)
            return true;
        if (index < n)
        {
            upd(curx, cury, s[index - k]);
            char c = s[index];
            if (c == 'U')
                c = 'D';
            else if (c == 'D')
                c = 'U';
            else if (c == 'R')
                c = 'L';
            else if (c == 'L')
                c = 'R';
            upd(curx, cury, c);
        }
        index++;
    }
    return false;
}

int main()
{
    int n, x, y;
    cin >> n >> s >> x >> y;
    if ((abs(x) + abs(y)) % 2 != n % 2)
    {
        cout << -1 << endl;
    }
    else if (abs(x) + abs(y) > n)
    {
        cout << -1 << endl;
    }
    else if (check(x, y, 0, n))
    {
        cout << 0 << endl;
    }
    else
    {
        int ans = -1;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (ans + jump <= n && !check(x, y, ans + jump, n))
            {
                ans += jump;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}