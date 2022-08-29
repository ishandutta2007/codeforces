#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N, people [MAXN], dp [MAXN][MAXN];
pair <int, int> choice [MAXN][MAXN];

int solve (int a, int b)
{
    if (dp [a][b] != -1)
        return dp [a][b];

    if (b >= N)
    {
        choice [a][b] = make_pair (a, a);
        return dp [a][b] = people [a];
    }
    else if (b == N - 1)
    {
        choice [a][b] = make_pair (a, b);
        return dp [a][b] = max (people [a], people [b]);
    }

    dp [a][b] = max (people [a], people [b]) + solve (b + 1, b + 2);
    choice [a][b] = make_pair (a, b);

    pair <int, int> p = make_pair (a, b + 1);
    int cost = max (people [a], people [b + 1]) + solve (b, b + 2);

    if (cost < dp [a][b])
    {
        dp [a][b] = cost;
        choice [a][b] = p;
    }

    p = make_pair (b, b + 1);
    cost = max (people [b], people [b + 1]) + solve (a, b + 2);

    if (cost < dp [a][b])
    {
        dp [a][b] = cost;
        choice [a][b] = p;
    }

    return dp [a][b];
}

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
        scanf ("%d", people + i);

    memset (dp, -1, sizeof (dp));
    printf ("%d\n", solve (0, 1));

    int a = 0, b = 1;

    while (true)
    {
        if (choice [a][b].first == choice [a][b].second)
            printf ("%d\n", choice [a][b].first + 1);
        else
            printf ("%d %d\n", choice [a][b].first + 1, choice [a][b].second + 1);

        if (b >= N - 1)
            break;

        if (choice [a][b] == make_pair (a, b))
        {
            a = b + 1;
            b = b + 2;
        }
        else if (choice [a][b] == make_pair (a, b + 1))
        {
            a = b;
            b = b + 2;
        }
        else if (choice [a][b] == make_pair (b, b + 1))
        {
            b = b + 2;
        }
    }

    return 0;
}