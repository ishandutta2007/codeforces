#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100005, TREE = 5 * MAX;

struct node
{
    long long sums [5];
    int index, lazy;
};

int N, E, PE, elem [MAX];
node tree [TREE];

char query [MAX];
int qnum [MAX];
char str [10];

inline void rotate (long long a [5], int shift)
{
    shift = (shift % 5 + 5) % 5;
    long long b [5];

    for (int i = 0; i < 5; i++)
        b [(i + shift) % 5] = a [i];

    for (int i = 0; i < 5; i++)
        a [i] = b [i];
}

inline void modify (int num, int offset)
{
    rotate (tree [num].sums, offset);
    tree [num].index += offset;
    tree [num].lazy += offset;
}

inline void push (int num, int start, int mid, int end)
{
    if (tree [num].lazy != 0)
    {
        if (start < E)
            modify (2 * num, tree [num].lazy);

        if (mid < E)
            modify (2 * num + 1, tree [num].lazy);

        tree [num].lazy = 0;
    }
}

inline void join (int num, int start, int mid, int end)
{
    for (int i = 0; i < 5; i++)
        tree [num].sums [i] = 0;

    if (start < E)
    {
        tree [num].index = tree [2 * num].index;

        for (int i = 0; i < 5; i++)
            tree [num].sums [i] += tree [2 * num].sums [i];
    }

    if (mid < E)
        for (int i = 0; i < 5; i++)
            tree [num].sums [i] += tree [2 * num + 1].sums [i];
}

void update (int num, int start, int end, int ind, int change)
{
    int mid = (start + end) >> 1;

    if (num >= PE && start == ind)
    {
        tree [num].sums [tree [num].index % 5] += change * elem [ind];
        return;
    }

    push (num, start, mid, end);

    if (ind < mid)
    {
        update (2 * num, start, mid, ind, change);
        modify (2 * num + 1, change);
    }
    else
        update (2 * num + 1, mid, end, ind, change);

    join (num, start, mid, end);
}

int main ()
{
    scanf ("%d", &N);
    E = 0;

    for (int i = 0; i < N; i++)
    {
        scanf ("%s", str);
        query [i] = str [0];

        if (query [i] == 'a' || query [i] == 'd')
        {
            scanf ("%d", qnum + i);
            elem [E++] = qnum [i];
        }
    }

    sort (elem, elem + E);
    E = unique (elem, elem + E) - elem;
    PE = 1 << (32 - __builtin_clz (E));

    for (int i = 0; i < N; i++)
        if (query [i] == 's')
            cout << tree [1].sums [2] << '\n';
        else
        {
            int ind = lower_bound (elem, elem + E, qnum [i]) - elem;
            update (1, 0, PE, ind, query [i] == 'a' ? +1 : -1);
        }

    return 0;
}