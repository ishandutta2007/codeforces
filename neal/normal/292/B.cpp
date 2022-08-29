#include <cstdio>
#include <vector>
using namespace std;

const int NM_MAX = 100005;

int N, M;
vector<int> adj[NM_MAX];

bool is_bus()
{
    if (M != N - 1)
        return false;

    int ones = 0;

    for (int i = 0; i < N; i++)
    {
        if (adj[i].size() > 2)
            return false;

        if (adj[i].size() == 1)
            ones++;
    }

    return ones == 2;
}

bool is_ring()
{
    if (M != N)
        return false;

    for (int i = 0; i < N; i++)
        if (adj[i].size() != 2)
            return false;

    return true;
}

bool is_star()
{
    if (M != N - 1)
        return false;

    for (int i = 0; i < N; i++)
        if (adj[i].size() != 1 && (int) adj[i].size() != N - 1)
            return false;

    return true;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (is_bus())
        puts("bus topology");
    else if (is_ring())
        puts("ring topology");
    else if (is_star())
        puts("star topology");
    else
        puts("unknown topology");

    return 0;
}