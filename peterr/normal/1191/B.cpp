#include <bits/stdc++.h>

using namespace std;

int cards[3][10];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        int num = stoi(s.substr(0, 1));
        char suit = s[1];
        int suitnum;
        if (suit == 'm')
            suitnum = 0;
        else if (suit == 'p')
            suitnum = 1;
        else
            suitnum = 2;
        cards[suitnum][num]++;
    }
    int ans = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans = min(ans, 3 - cards[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            int has = 0;
            for (int k = 0; k < 3; k++)
            {
                if (cards[i][j+k] > 0)
                    has++;
            }
            ans = min(ans, 3 - has);
        }
    }
    cout << ans;
    return 0;
}