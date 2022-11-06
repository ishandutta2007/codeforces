#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, i, e;
        cin >> s >> i >> e;
        if (s + e <= i)
        {
            cout << 0 << endl;
        }
        else if (i + e < s)
        {
            cout << e + 1 << endl;
        }
        else
        {
            int points = -1;
            for (int jump = e / 2 + 1; jump > 0; jump /= 2)
            {
                while (points + jump < e && s + points + jump <= i + (e - points - jump))
                {
                    points += jump;
                }
            }
            points++;
            cout << e - points + 1 << endl;
        }

    }
    return 0;
}