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

inline bool lucky (long long x)
{
    assert (x >= 0);

    while (x != 0)
    {
        if (x % 10 != 4 && x % 10 != 7)
            return false;

        x /= 10;
    }

    return true;
}

const int MAXN = 100005;

int N, up [MAXN];
bool up_lucky [MAXN];
vector <int> adj [MAXN];
vector <bool> adj_lucky [MAXN];
int sub [MAXN], dp [MAXN];
long long total = 0;

void dfs (int num, int parent)
{
    up [num] = parent;
    sub [num] = 1;
    dp [num] = 0;

    for (int i = 0; i < (int) adj [num].size (); i++)
        if (adj [num][i] != parent)
        {
            int next = adj [num][i];
            up_lucky [next] = adj_lucky [num][i];
            dfs (next, num);
            sub [num] += sub [next];

            if (up_lucky [next])
                dp [num] += sub [next];
            else
                dp [num] += dp [next];
        }
}

void dfs_solve (int num, int add)
{
    int paths = dp [num] + add;
//    printf ("%d %d\n", num + 1, paths);
    total += (long long) paths * (paths - 1);

    for (int i = 0; i < (int) adj [num].size (); i++)
    {
        int next = adj [num][i];

        if (next == up [num])
            continue;

        if (up_lucky [next])
            dfs_solve (next, N - sub [next]);
        else
            dfs_solve (next, add + dp [num] - dp [next]);
    }
}

int dfs_slow (int num, int parent, bool luck)
{
    int count = luck ? 1 : 0;

    for (int i = 0; i < (int) adj [num].size (); i++)
        if (adj [num][i] != parent)
            count += dfs_slow (adj [num][i], num, luck || adj_lucky [num][i]);

    return count;
}

int main ()
{
    scanf ("%d", &N);

    for (int a, b, w, i = 1; i < N; i++)
    {
        scanf ("%d %d %d", &a, &b, &w); a--; b--;
        adj [a].push_back (b);
        adj [b].push_back (a);
        adj_lucky [a].push_back (lucky (w));
        adj_lucky [b].push_back (lucky (w));
    }

    up_lucky [0] = false;
    dfs (0, -1);
    dfs_solve (0, 0);
/*
    long long slow_total = 0;

    for (int i = 0; i < N; i++)
    {
        long long count = dfs_slow (i, -1, false);
        slow_total += count * (count - 1);

    }
    cout << slow_total << '\n';
*/
    cout << total << '\n';
    return 0;
}