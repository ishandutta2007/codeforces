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

const double EPS = 1e-10;

bool possible(int n, int r, int R)
{
    if (r > R)
        return false;

    if (n == 1)
        return true;

    if (2 * (R - r) < 2 * r)
        return false;

    double angle = 2 * asin((double) r / (R - r));
    return n * angle <= 2 * M_PI + EPS;
}

int main ()
{
    int n, r, R;
    scanf("%d %d %d", &n, &R, &r);
    puts(possible(n, r, R) ? "YES" : "NO");
    return 0;
}