#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAXN = 100005;

struct edge
{
    int a, b, length, orig_ind;

    inline bool operator < (const edge &o) const
    {
        return length < o.length;
    }
};

int N, parent [MAXN], rank [MAXN], size [MAXN];
edge roads [MAXN];

inline int find (int x)
{
    return x == parent [x] ? x : parent [x] = find (parent [x]);
}

inline void join (int x, int y)
{
    x = find (x); y = find (y);
    assert (x != y);

    if (rank [x] >= rank [y])
    {
        parent [y] = x;
        size [x] += size [y];

        if (rank [x] == rank [y])
            rank [x]++;
    }
    else
    {
        parent [x] = y;
        size [y] += size [x];
    }
}

int up [MAXN], subtree [MAXN];
vector <int> adj [MAXN];

void dfs (int num)
{
    subtree [num] = size [num];

    for (int i = 0; i < (int) adj [num].size (); i++)
    {
        int next = adj [num][i];

        if (up [next] == -1)
        {
            up [next] = up [num];
            dfs (next);
            subtree [num] += subtree [next];
        }
    }
}

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
    {
        parent [i] = i;
        rank [i] = 0;
        size [i] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        scanf ("%d %d %d", &roads [i].a, &roads [i].b, &roads [i].length);
        roads [i].a--; roads [i].b--;
        roads [i].orig_ind = i;
    }

    sort (roads + 1, roads + N);
    long long best_trees = -1;
    vector <int> best_roads;

    for (int i = 1, j = 1; i < N; i = j)
    {
        while (j < N && roads [i].length == roads [j].length)
            j++;

        for (int k = i; k < j; k++)
        {
            roads [k].a = find (roads [k].a);
            roads [k].b = find (roads [k].b);
            up [roads [k].a] = up [roads [k].b] = -1;
            adj [roads [k].a].push_back (roads [k].b);
            adj [roads [k].b].push_back (roads [k].a);
        }

        for (int k = i; k < j; k++)
            if (up [roads [k].a] == -1)
            {
                up [roads [k].a] = roads [k].a;
                dfs (roads [k].a);
            }

        for (int k = i; k < j; k++)
        {
            long long sub = min (subtree [roads [k].a], subtree [roads [k].b]);
            long long upsub = subtree [up [roads [k].a]];
            assert (up [roads [k].a] != -1);
            assert (up [roads [k].a] == up [roads [k].b]);
            long long mult = sub * (upsub - sub);
//            fprintf (stderr, "%d %d %d %lld\n", roads [k].a + 1, roads [k].b + 1, roads [k].length, mult);

            if (mult > best_trees)
            {
                best_trees = mult;
                best_roads.clear ();
                best_roads.push_back (roads [k].orig_ind);
            }
            else if (mult == best_trees)
                best_roads.push_back (roads [k].orig_ind);
        }

        for (int k = i; k < j; k++)
        {
            adj [roads [k].a].clear ();
            adj [roads [k].b].clear ();
            join (roads [k].a, roads [k].b);
        }
    }

    sort (best_roads.begin (), best_roads.end ());
    cout << 2 * best_trees << ' ' << best_roads.size () << '\n';

    for (int i = 0; i < (int) best_roads.size (); i++)
        cout << best_roads [i] << (i + 1 < (int) best_roads.size () ? ' ' : '\n');

    return 0;
}