#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 185, INF = 1000000005;

int N, K, D [MAXN], center [MAXN], min_sub [MAXN], sub_cent [MAXN];
int dist [MAXN][MAXN], dp [MAXN][MAXN];
vector <int> adj [MAXN];

void dist_dfs (int orig, int num, int par, int d)
{
    dist [orig][num] = d;

    for (int i = 0; i < (int) adj [num].size (); i++)
        if (adj [num][i] != par)
            dist_dfs (orig, adj [num][i], num, d + 1);
}

void solve (int num, int par)
{
    for (int i = 0; i < (int) adj [num].size (); i++)
        if (adj [num][i] != par)
            solve (adj [num][i], num);

    for (int cent = 0; cent < N; cent++)
    {
        dp [num][cent] = D [dist [num][cent]];

        for (int i = 0; i < (int) adj [num].size (); i++)
        {
            int next = adj [num][i];

            if (next != par)
                dp [num][cent] += min (dp [next][cent], min_sub [next] + K);
        }
    }

    min_sub [num] = INF;

    for (int i = 0; i < N; i++)
        if (dist [i][num] < dist [i][par] + 1 && dp [num][i] < min_sub [num])
        {
            min_sub [num] = dp [num][i];
            sub_cent [num] = i;
        }
}

void appoint (int num, int par, int cent)
{
    center [num] = cent;

    for (int i = 0; i < (int) adj [num].size (); i++)
    {
        int next = adj [num][i];

        if (next != par)
            appoint (next, num, dp [next][cent] < min_sub [next] + K ? cent : sub_cent [next]);
    }
}

int main ()
{
    scanf ("%d %d", &N, &K);
    D [0] = 0;

    for (int i = 1; i <= N - 1; i++)
        scanf ("%d", D + i);

    for (int i = 1, a, b; i < N; i++)
    {
        scanf ("%d %d", &a, &b); a--; b--;
        adj [a].push_back (b);
        adj [b].push_back (a);
    }

    for (int i = 0; i < N; i++)
        dist_dfs (i, i, -1, 0);

    solve (0, -1);
    int best = -1;

    for (int i = 0; i < N; i++)
        if (best == -1 || dp [0][i] < dp [0][best])
            best = i;

    printf ("%d\n", dp [0][best] + K);
    appoint (0, -1, best);

    for (int i = 0; i < N; i++)
        printf ("%d%c", center [i] + 1, i < N - 1 ? ' ' : '\n');

    return 0;
}