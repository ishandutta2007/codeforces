#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, sub_nodes [MAXN], total_length [MAXN], up_edge [MAXN];
vector <int> adj [MAXN], adj_length [MAXN];

void dfs (int num, int parent)
{
    sub_nodes [num] = 1;
    total_length [num] = 0;
    up_edge [num] = 0;

    for (int i = 0; i < (int) adj [num].size (); i++)
    {
        int neighbor = adj [num][i];

        if (neighbor == parent)
            continue;

        dfs (neighbor, num);
        up_edge [adj [num][i]] = adj_length [num][i];
        sub_nodes [num] += sub_nodes [neighbor];
        total_length [num] += adj_length [num][i] + total_length [neighbor];
    }
}

inline bool compare (int a, int b)
{
    return (long long) (up_edge [a] + total_length [a]) * sub_nodes [b] < (long long) (up_edge [b] + total_length [b]) * sub_nodes [a];
}

long long solve (int num, int parent, int start)
{
    vector <int> children;

    for (int i = 0; i < (int) adj [num].size (); i++)
    {
        int neighbor = adj [num][i];

        if (neighbor != parent)
            children.push_back (neighbor);
    }

    sort (children.begin (), children.end (), compare);
    long long total = start;

    for (int i = 0; i < (int) children.size (); i++)
    {
        int child = children [i];
        total += solve (child, num, start + up_edge [child]);
        start += 2 * (up_edge [child] + total_length [child]);
    }

    return total;
}

int main ()
{
    scanf ("%d", &N);

    for (int a, b, len, i = 1; i < N; i++)
    {
        scanf ("%d %d %d", &a, &b, &len); a--; b--;
        adj [a].push_back (b);
        adj [b].push_back (a);
        adj_length [a].push_back (len);
        adj_length [b].push_back (len);
    }

    dfs (0, -1);
    printf ("%.12lf\n", (double) solve (0, -1, 0) / (N - 1));
    return 0;
}