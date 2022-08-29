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

const int MAXN = 100005, MAXM = 10005;

struct tree
{
    int loc, height, left, right;
};

struct mushroom
{
    int loc, power;

    bool operator < (const mushroom &o) const
    {
        return loc < o.loc;
    }
};

struct probability
{
    double log;
    int zeroes;

    double value () const
    {
        return zeroes > 0 ? 0 : exp (log);
    }

    probability operator * (const probability &o) const
    {
        probability prob = *this;
        prob.log += o.log;
        prob.zeroes += o.zeroes;
        return prob;
    }

    probability operator / (const probability &o) const
    {
        probability prob = *this;
        prob.log -= o.log;
        prob.zeroes -= o.zeroes;
        return prob;
    }
};

struct event
{
    int loc;
    probability change;
    bool add;

    bool operator < (const event &o) const
    {
        return loc < o.loc;
    }
};

int N, M;
tree trees [MAXN];
mushroom mushrooms [MAXM];
int E;
event events [4 * MAXN];

probability int_to_prob (int p)
{
    if (p == 0)
        return (probability) {0, 1};
    else
        return (probability) {log (p / 100.0), 0};
}

int main ()
{
    scanf ("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf ("%d %d %d %d", &trees [i].loc, &trees [i].height, &trees [i].left, &trees [i].right);
        events [E++] = (event) {trees [i].loc - trees [i].height, int_to_prob (100 - trees [i].left), true};
        events [E++] = (event) {trees [i].loc, int_to_prob (100 - trees [i].left), false};
        events [E++] = (event) {trees [i].loc + 1, int_to_prob (100 - trees [i].right), true};
        events [E++] = (event) {trees [i].loc + trees [i].height + 1, int_to_prob (100 - trees [i].right), false};
    }

    sort (events, events + E);

    for (int i = 0; i < M; i++)
        scanf ("%d %d", &mushrooms [i].loc, &mushrooms [i].power);

    sort (mushrooms, mushrooms + M);
    probability p = (probability) {0, 0};
    double total = 0;

    for (int i = 0, e = 0; i < M; i++)
    {
        while (e < E && events [e].loc <= mushrooms [i].loc)
        {
            p = events [e].add ? p * events [e].change : p / events [e].change;
            e++;
        }

        total += p.value () * mushrooms [i].power;
    }

    printf ("%lf\n", total);
    return 0;
}