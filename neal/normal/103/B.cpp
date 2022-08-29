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

const int MAXN = 105;

int N, M;
bool vis [MAXN], edge [MAXN][MAXN];

void dfs (int num)
{
    vis [num] = true;

    for (int i = 0; i < N; i++)
        if (edge [num][i] && !vis [i])
            dfs (i);
}

int main ()
{
    scanf ("%d %d", &N, &M);

    if (N != M)
    {
        puts ("NO");
        return 0;
    }

    for (int a, b, i = 0; i < M; i++)
    {
        scanf ("%d %d", &a, &b); a--; b--;
        edge [a][b] = edge [b][a] = true;
    }

    dfs (0);

    for (int i = 0; i < N; i++)
        if (!vis [i])
        {
            puts ("NO");
            return 0;
        }

    puts ("FHTAGN!");
    return 0;
}