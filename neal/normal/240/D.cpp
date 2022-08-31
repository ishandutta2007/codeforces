#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int NM_MAX = 100005;

int N, M, cards[2 * NM_MAX];

pair<vector<int>, int> construct(int look)
{
    vector<int> deck;
    int a = 0, b = N, score = 0;
    bool start = true;

    while (a < N || b < N + M)
    {
        int take;

        if (a < N && (b == N + M || cards[a] == look))
            take = a++;
        else
            take = b++;

        deck.push_back(take);

        if (cards[take] == 1 && (start || look == 0))
            score += start ? 1 : 2;

        look = cards[take];
        start = false;
    }

    return make_pair(deck, score);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]);

    scanf("%d", &M);

    for (int i = N; i < N + M; i++)
        scanf("%d", &cards[i]);

    pair<vector<int>, int> start0 = construct(0), start1 = construct(1);
    pair<vector<int>, int> better = start0.second < start1.second ? start0 : start1;

    for (int i = 0; i < (int) better.first.size(); i++)
        printf("%d%c", better.first[i] + 1, i < (int) better.first.size() - 1 ? ' ' : '\n');

    printf("%d\n", better.second);
    int count = 0;

    for (int i = 0; i < (int) better.first.size() - 1; i++)
        if (cards[better.first[i]] != cards[better.first[i + 1]])
            printf("%d%c", i + 1, count++ < better.second - 1 ? ' ' : '\n');

    if (count < better.second)
    {
        printf("%d\n", N + M);
        count++;
    }

    assert(count == better.second);
    return 0;
}