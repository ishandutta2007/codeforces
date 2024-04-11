#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

int N, prio [MAXN], parent [MAXN], cap [MAXN], days [MAXN];
vector <int> adj [MAXN], capacity [MAXN];
int front, back, q [MAXN];
int hold [MAXN][MAXN], hsize [MAXN];

void bfs ()
{
    memset (parent, -1, sizeof (parent));
    front = back = 0;
    parent [0] = 0;
    q [back++] = 0;

    while (front < back)
    {
        int top = q [front++];

        for (int i = 0; i < (int) adj [top].size (); i++)
            if (parent [adj [top][i]] == -1)
            {
                parent [adj [top][i]] = top;
                cap [adj [top][i]] = capacity [top][i];
                q [back++] = adj [top][i];
            }
    }
}

inline void add_hold (int v, int h)
{
    hold [v][hsize [v]++] = h;
}

inline bool compare (int a, int b)
{
    return prio [a] > prio [b];
}

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
        scanf ("%d", prio + i);

    for (int i = 1, a, b, c; i < N; i++)
    {
        scanf ("%d %d %d", &a, &b, &c); a--; b--;
        adj [a].push_back (b);
        adj [b].push_back (a);
        capacity [a].push_back (c);
        capacity [b].push_back (c);
    }

    bfs ();
    memset (days, -1, sizeof (days));
    int arrive = 0;

    for (int i = 0; i < N; i++)
    {
        hsize [i] = 1;
        hold [i][0] = i;
    }

    for (int day = 0; arrive < N; day++)
    {
        for (int i = 0; i < hsize [0]; i++)
            if (days [hold [0][i]] == -1)
            {
                days [hold [0][i]] = day;
                arrive++;
            }

        for (int it = 1; it < N; it++)
        {
            int v = q [it];

            if (cap [v] >= hsize [v])
            {
                for (int i = 0; i < hsize [v]; i++)
                    add_hold (parent [v], hold [v][i]);

                hsize [v] = 0;
            }
            else
            {
                nth_element (hold [v], hold [v] + hsize [v] - cap [v], hold [v] + hsize [v], compare);

                for (int i = hsize [v] - cap [v]; i < hsize [v]; i++)
                    add_hold (parent [v], hold [v][i]);

                hsize [v] -= cap [v];
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf ("%d%c", days [i], i < N - 1 ? ' ' : '\n');

    return 0;
}