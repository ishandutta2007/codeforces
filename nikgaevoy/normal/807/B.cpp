#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = int (1e9) + 7;

bool t_shirt (int s, int p)
{
    s /= 50;
    s %= 475;

    for (int i = 0; i < 25; i++)
    {
        s = (s * 96 + 42) % 475;

        if (p == 26 + s)
            return true;
    }

    return false;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int p, x, y;

    cin >> p >> x >> y;

    int s = y - (y % 50) + x % 50;

    while (s < y)
        s += 50;

    while (!t_shirt (s, p))
        s += 50;

    cout << max (0, (s - x + 50) / 100) << endl;

    return 0;
}