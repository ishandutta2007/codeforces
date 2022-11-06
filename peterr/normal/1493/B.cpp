#include <bits/stdc++.h>

using namespace std;

bool reflect(int x, int &res)
{
    if (x == 3 || x == 4 || x == 6 || x == 7 || x == 9)
        return false;
    if (x == 0 || x == 1 || x == 8)
        res = x;
    else if (x == 2)
        res = 5;
    else if (x == 5)
        res = 2;
    return true;
}

bool isValid(int h, int m, int hh, int mm)
{
    int a, b, c, d;
    if (!reflect(hh / 10, a) || !reflect(hh % 10, b) || !reflect(mm / 10, c) || !reflect(mm % 10, d))
        return false;
    return d * 10 + c < h && b * 10 + a < m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        string s;
        cin >> h >> m >> s;
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3));
        while (1)
        {
            if (isValid(h, m, hh, mm))
            {
                printf("%02d:%02d\n", hh, mm);
                break;
            }
            mm++;
            if (mm == m)
            {
                mm = 0;
                hh++;
                if (hh == h)
                    hh = 0;
            }
        }
    }
    return 0;
}