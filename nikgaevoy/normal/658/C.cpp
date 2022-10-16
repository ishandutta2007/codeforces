#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cassert>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const int inf = int (1e9) + 7;
const double pi = 3.1415926535897932384626433;
const double eps = 1e-4;

const string filename = "test";
const bool interactive = true;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n, d, h;

    cin >> n >> d >> h;

    if (h > d || (n > 2 && d == 1 && h == d) || n < d + 1 || d > 2 * h)
        cout << -1 << endl;
    else
    {
        int i = 2, b = 0;
        for (; b < h; i++, b++)
            printf ("%ld %ld\n", i - 1, i);

        int last = 1;
        int subroot = i - 2;
        for (; b < d; i++)
        {
            printf ("%ld %ld\n", last, i);
            b++;
            last = i;
        }
        while (b < n - 1)
        {
            printf ("%ld %ld\n", subroot, i++);
            b++;
        }
    }

    return 0;
}