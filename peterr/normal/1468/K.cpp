#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int encode(char c)
{
    if (c == 'U')
        return 0;
    if (c == 'L')
        return 1;
    if (c == 'D')
        return 2;
    return 3;
}

bool check(string &s, int x, int y)
{
    int xx = 0;
    int yy = 0;
    for (int i = 0; i < (int) s.length(); i++)
    {
        int newx = xx + dx[encode(s[i])];
        int newy = yy + dy[encode(s[i])];
        if (newx != x || newy != y)
        {
            xx = newx;
            yy = newy;
        }
    }
    return xx == 0 && yy == 0;
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
        int xx = 0;
        int yy = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < (int) s.length(); i++)
        {
            x += dx[encode(s[i])];
            y += dy[encode(s[i])];
            if (x != 0 || y != 0)
            {
                if (check(s, x, y))
                {
                    xx = x;
                    yy = y;
                }
            }
        }
        cout << xx << " " << yy << "\n";
    }
    return 0;
}