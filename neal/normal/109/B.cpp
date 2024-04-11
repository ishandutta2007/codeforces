// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1000000005;

vector <int> luckies;

void gen_lucky (int num, int dig)
{
    if (num > 0)
        luckies.push_back (num);

    if (dig < 9)
    {
        gen_lucky (10 * num + 4, dig + 1);
        gen_lucky (10 * num + 7, dig + 1);
    }
}

int PL, PR, VL, VR, K;

inline int intersect (int a, int b, int c, int d)
{
    return max (min (b, d) - max (a, c) + 1, 0);
}

int main ()
{
    gen_lucky (0, 0);
    sort (luckies.begin (), luckies.end ());
    scanf ("%d %d %d %d %d", &PL, &PR, &VL, &VR, &K);
    double total = 0;

    for (int i = 0; i + K <= (int) luckies.size (); i++)
    {
        int low = i == 0 ? -INF : luckies [i - 1] + 1;
        int high = i + K == (int) luckies.size () ? INF : luckies [i + K] - 1;
        total += (double) intersect (low, luckies [i], PL, PR) * intersect (luckies [i + K - 1], high, VL, VR) + (double) intersect (low, luckies [i], VL, VR) * intersect (luckies [i + K - 1], high, PL, PR);

        if (K == 1 && PL <= luckies [i] && luckies [i] <= PR && VL <= luckies [i] && luckies [i] <= VR)
            total--;
    }

    printf ("%.12lf\n", total / (PR - PL + 1) / (VR - VL + 1));
    return 0;
}