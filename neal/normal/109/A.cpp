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

int N;

int main ()
{
    scanf ("%d", &N);

    for (int digits = 1; digits <= N; digits++)
    {
        int sevens = N - 4 * digits;

        if (sevens % 3 != 0 || sevens < 0)
            continue;

        sevens /= 3;

        if (sevens > digits)
            continue;

        for (int i = 0; i < digits; i++)
            putchar (i < digits - sevens ? '4' : '7');

        putchar ('\n');
        return 0;
    }

    puts ("-1");
    return 0;
}