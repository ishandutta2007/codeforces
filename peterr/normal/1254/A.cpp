#include <bits/stdc++.h>

using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int MAXR = 100;
bool rice[MAXR][MAXR];
char ans[MAXR][MAXR];
string keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c, k;
        cin >> r >> c >> k;
        int rices = 0;
        for (int i = 0; i < r; i++)
        {
            string line;
            cin >> line;
            for (int j = 0; j < c; j++)
            {
                rice[i][j] = line[j] == 'R';
                if (rice[i][j])
                    rices++;
            }
        }
        int cur = 0;
        int dir = c == 1 ? DOWN : RIGHT;
        int rr = 0, cc = 0;
        int feed = rices / k;
        int extra = rices % k;
        int cnt = 0;
        while (rr < r)
        {
            ans[rr][cc] = keys[min(cur, k - 1)];
            if (rice[rr][cc])
            {
                cnt++;
            }
            if (dir == RIGHT)
            {
                cc++;
                if (cc == c - 1)
                    dir = DOWN;
            }
            else if (dir == DOWN)
            {
                rr++;
                if (c != 1)
                {
                    if (cc == 0)
                        dir = RIGHT;
                    else
                        dir = LEFT;
                }
            }
            else if (dir == LEFT)
            {
                cc--;
                if (cc == 0)
                    dir = DOWN;
            }
            if (extra > 0)
            {
                if (cnt == feed + 1)
                {
                    cur++;
                    extra--;
                    cnt = 0;
                }
            }
            else
            {
                if (cnt == feed)
                {
                    cur++;
                    cnt = 0;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}