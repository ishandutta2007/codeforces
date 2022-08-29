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

const int N_MAX = 305;

int N, gerard[N_MAX], friends[N_MAX][N_MAX];
int fvalue[N_MAX], gvalue[N_MAX];

int solve(int f)
{
    for (int i = 0; i < N; i++)
        fvalue[friends[f][i]] = i;

    for (int i = 0; i < N; i++)
        gvalue[gerard[i]] = i;

    int gv = N_MAX, fv = N_MAX, gift = -1;

    for (int i = 0; i < N; i++)
        if (i != f)
        {
            if (gvalue[i] < gv)
            {
                gv = gvalue[i];

                if (fvalue[i] < fv)
                {
                    fv = fvalue[i];
                    gift = i;
                }
            }
        }

    return gift;
}

int main ()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &friends[i][j]);
            friends[i][j]--;
        }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &gerard[i]);
        gerard[i]--;
    }

    for (int i = 0; i < N; i++)
        printf("%d%c", solve(i) + 1, i < N - 1 ? ' ' : '\n');

    return 0;
}