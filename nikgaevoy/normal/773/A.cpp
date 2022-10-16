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

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int t;

    cin >> t;

    while (t-- > 0)
    {
        long long x, y, p, q;

        cin >> x >> y >> p >> q;

        if (p * y > x * q)
        {
            x = y - x;
            p = q - p;
        }

        if (q == 1)
        {
            if (p == 0)
                cout << (x == 0 ? 0 : -1) << endl;
            else
                cout << (x == y ? 0 : -1) << endl;

            continue;
        }

        long long ny = (x * q + p - 1) / p;
        if (ny % q != 0)
            ny += q - (ny % q);
        cout << ny - y << endl;
    }

    return 0;
}