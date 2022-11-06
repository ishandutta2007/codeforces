#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int px, py;
        string s;
        cin >> px >> py >> s;
        for (char ch : s)
        {
            if (ch == 'U' && py > 0)
                py--;
            else if (ch == 'D' && py < 0)
                py++;
            else if (ch == 'R' && px > 0)
                px--;
            else if (ch == 'L' && px < 0)
                px++;
        }
        if (px || py)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}