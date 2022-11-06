#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int arr[MAXN];

int main()
{
    int n;
    cin >> n;
    bool infinite = false;
    int prev = -1;
    int prevprev = -1;
    int cur = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        prevprev = prev;
        prev = cur;
        cin >> cur;
        if (cur == 1)
        {
            if (prev == 2)
                ans += 3;
            else if (prev == 3)
                ans += 4;
        }
        else if (cur == 2)
        {
            if (prev == 1)
                if (prevprev == 3)
                    ans += 2;
                else
                    ans += 3;
            else if (prev == 3)
                infinite = true;
        }
        else if (cur == 3)
        {
            if (prev == 1)
                ans += 4;
            else if (prev == 2)
                infinite = true;
        }
    }
    if (infinite)
    {
        cout << "Infinite" << endl;
    }
    else
    {
        cout << "Finite" << endl;
        cout << ans << endl;
    }
    return 0;
}