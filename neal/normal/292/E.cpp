#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N_MAX = 100005, TREE = 3 * N_MAX, INF = 1000000005;

int N, M;
int P, PN, tree[TREE], change[TREE];
int A[N_MAX], B[N_MAX];

int tree_start(int pos)
{
    int level = 31 - __builtin_clz(pos);
    return min((pos - (1 << level)) << (P - level), N);
}

int tree_end(int pos)
{
    int level = 31 - __builtin_clz(pos);
    return min((pos - (1 << level) + 1) << (P - level), N);
}

void modify(int pos, int val)
{
    tree[pos] = change[pos] = val;
}

void push(int pos)
{
    if (pos < PN && change[pos] < INF)
    {
        modify(2 * pos, change[pos]);
        modify(2 * pos + 1, change[pos]);
        change[pos] = INF;
    }
}

void join(int pos)
{
    if (pos < PN)
        tree[pos] = tree[2 * pos] < INF ? tree[2 * pos] : tree[2 * pos + 1];
}

int solve(int pos, int a, int b)
{
    int start = tree_start(pos), end = tree_end(pos);

    if (a <= start && end <= b)
        return tree[pos];

    if (pos >= PN || start >= b || a >= end)
        return INF;

    push(pos);
    int answer1 = solve(2 * pos, a, b), answer2 = solve(2 * pos + 1, a, b);
    return answer1 < INF ? answer1 : answer2;
}

void update(int pos, int a, int b, int val)
{
    int start = tree_start(pos), end = tree_end(pos);

    if (a <= start && end <= b)
    {
        modify(pos, val);
        return;
    }

    if (pos >= PN || start >= b || a >= end)
        return;

    push(pos);
    update(2 * pos, a, b, val);
    update(2 * pos + 1, a, b, val);
    join(pos);
}

int main()
{
    for (int i = 0; i < TREE; i++)
        tree[i] = change[i] = INF;

    scanf("%d %d", &N, &M);
    P = 32 - __builtin_clz(N);
    PN = 1 << P;

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    for (int i = 0; i < M; i++)
    {
        int type;
        scanf("%d", &type);

        if (type == 1)
        {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            x--; y--;
            update(1, y, y + k, x - y);
        }
        else
        {
            int x;
            scanf("%d", &x);
            x--;

            int delta = solve(1, x, x + 1);

            if (delta < INF)
                printf("%d\n", A[x + delta]);
            else
                printf("%d\n", B[x]);
        }
    }

    return 0;
}