#define NDEBUG
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

struct UnionFind
{
    int n;
    unsigned char *rank;
    int *parent;

    void init(int _n)
    {
        if (rank != NULL)
            delete[] rank;

        if (parent != NULL)
            delete[] parent;

        n = _n;
        rank = new unsigned char[n];
        parent = new int[n];

        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    UnionFind()
    {
        rank = NULL;
        parent = NULL;
    }

    UnionFind(int _n)
    {
        init(_n);
    }

    int find(int x)
    {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool join(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (rank[x] >= rank [y])
        {
            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;
        }
        else
            parent[x] = y;

        return true;
    }
};

const int M_MAX = 100005;

struct edge
{
    int a, b;
    char who;
};

int N, M, H;
edge edges [M_MAX];
UnionFind S_UF, M_UF;

void impossible()
{
    puts("-1");
    exit(0);
}

int main()
{
    scanf("%d %d", &N, &M);
    S_UF.init(N);
    M_UF.init(N);

    if (N % 2 == 0)
        impossible();

    H = (N - 1) / 2;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %c", &edges[i].a, &edges[i].b, &edges[i].who);
        edges[i].a--; edges[i].b--;
    }

    int S = 0;

    for (int i = 0; i < M; i++)
        if (edges[i].who == 'S')
            if (S_UF.join(edges[i].a, edges[i].b))
                S++;

    if (S < H)
        impossible();

    int components = N - S;
    vector<int> answer;

    for (int i = 0; i < M && (int) answer.size() < H - (components - 1); i++)
        if (edges[i].who == 'M')
            if (S_UF.find(edges[i].a) == S_UF.find(edges[i].b))
                if (M_UF.join(edges[i].a, edges[i].b))
                    answer.push_back(i);

    assert((int) answer.size() <= H - (components - 1));

    if ((int) answer.size() != H - (components - 1))
        impossible();

    for (int i = 0; i < M; i++)
        if (edges[i].who == 'M')
            if (S_UF.join(edges[i].a, edges[i].b))
            {
                assert(M_UF.join(edges[i].a, edges[i].b));
                answer.push_back(i);
            }

    assert((int) answer.size() <= H);

    if ((int) answer.size() != H)
        impossible();

    for (int i = 0; i < M; i++)
        if (edges[i].who == 'S')
            if (M_UF.join(edges[i].a, edges[i].b))
                answer.push_back(i);

    assert((int) answer.size() == N - 1);
    printf("%d\n", (int) answer.size());

    for (int i = 0; i < (int) answer.size(); i++)
        printf("%d%c", answer[i] + 1, i < (int) answer.size() - 1 ? ' ' : '\n');

    return 0;
}