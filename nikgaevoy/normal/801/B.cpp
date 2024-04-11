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

    string x, y;

    cin >> x >> y;

    for (size_t i = 0; i < min (x.size (), y.size ()); i++)
        if (y[i] > x[i])
        {
            cout << -1 << endl;

            return 0;
        }

    cout << y << endl;

    return 0;
}