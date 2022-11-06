#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5;
int hand[MAXN];
int deck[MAXN];
int early[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hand[i];
    for (int i = 0; i < n; i++)
        cin >> deck[i];
    for (int i = 0; i < n; i++)
    {
        if (hand[i])
        {
            early[hand[i]] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (deck[i])
        {
            early[deck[i]] = i + 2;
        }
    }

    if (early[1] > 1)
    {
        int index = early[1] - 2;
        bool increasing = true;
        for (int i = index + 1; i < n; i++)
        {
            if (deck[i]  - deck[i-1] != 1)
                increasing = false;
        }
        if (increasing)
        {
            int start = n - index + 1;
            bool good = true;
            int count = 1;
            while (start <= n)
            {
                if (early[start] > count)
                    good = false;
                count++;
                start++;
            }

            if (good)
            {
                cout << (count - 1);
                return 0;
            }
        }
    }
    int turns = 0;
    for (int i = 1; i <= n; i++)
    {
        turns++;
        turns = max(turns, early[i]);
    }

    cout << turns;

    return 0;
}