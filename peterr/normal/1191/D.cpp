#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long stones[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    sort(stones, stones + n);
    bool tokitWin = false;
    if (n == 1)
    {
        tokitWin = (stones[0] % 2 == 1);
    }
    else
    {
        bool repeat = false;
        bool done = false;
        bool isStair = true;
        if (stones[1] == 0)
        {
            tokitWin = false;
            done = true;
        }
        for (int i = 0; !done && i < n; i++)
        {
            if (stones[i] != i)
                isStair = false;
            if (i < n - 1 && stones[i] == stones[i + 1])
            {
                if (!repeat)
                {
                    repeat = true;
                    if (i > 0 && stones[i - 1] == stones[i] - 1)
                    {
                        tokitWin = false;
                        done = true;
                    }
                    stones[i]--;
                }
                else
                {
                    tokitWin = false;
                    done = true;
                }
            }
        }
        if (!done && isStair)
        {
            tokitWin = false;
            done = true;
        }
        else if (!done)
        {
            long long dist = 0;
            for (int i = 0; i < n; i++)
            {
                dist += stones[i] - i;
            }
            if (repeat)
                tokitWin = (dist % 2 == 0);
            else
                tokitWin = (dist % 2 == 1);
        }
    }
    if (tokitWin)
        cout << "sjfnb";
    else
        cout << "cslnb";

    return 0;
}