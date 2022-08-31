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

const int MAXN = 200005, INF = 1000000005;

int N, T, psum [MAXN], tree [3 * MAXN];
char str [MAXN];

int query (int value)
{
    int least = INF;

    for (int i = value; i > 0; i -= i & -i)
        least = min (least, tree [i]);

    return least;
}

void update (int value, int ind)
{
    for (int i = value; i <= T; i += i & -i)
        tree [i] = min (tree [i], ind);
}

bool isvowel (char c)
{
    c = tolower (c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main ()
{
    memset (tree, 63, sizeof (tree));
    scanf ("%s", str);
    N = strlen (str);
    T = 3 * N + 5;
    psum [0] = 0;

    for (int i = 0; i < N; i++)
        psum [i + 1] = psum [i] + (isvowel (str [i]) ? -1 : 2);

    int longest = -INF;

    for (int i = 0; i <= N; i++)
    {
        int value = psum [i] + N + 1;
        longest = max (longest, i - query (value));
        update (value, i);
    }

    if (longest <= 0)
    {
        puts ("No solution");
        return 0;
    }

    int count = 0;

    for (int i = 0; i + longest <= N; i++)
        if (psum [i + longest] >= psum [i])
            count++;

    printf ("%d %d\n", longest, count);
    assert (count > 0);
    return 0;
}