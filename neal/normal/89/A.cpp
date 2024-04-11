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

int N, M, K;

int main ()
{
    scanf ("%d %d %d", &N, &M, &K);

    if (N % 2 == 0)
    {
        puts ("0");
        return 0;
    }

    long long least = (long long) K * (M / (N / 2 + 1));

    for (int d, i = 0; i < N; i++)
    {
        scanf ("%d", &d);

        if (i % 2 == 0)
            least = min (least, (long long) d);
    }

    printf ("%d\n", (int) least);
    return 0;
}