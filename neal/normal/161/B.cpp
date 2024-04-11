// #define NDEBUG
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

const int NK_MAX = 2005;
const int STOOL = 1, PENCIL = 2;

struct item
{
    int price, type, original;

    bool operator < (const item &o) const
    {
        return price < o.price;
    }
};

int N, K;
item items[NK_MAX];
vector<int> carts[NK_MAX];

int main()
{
    scanf("%d %d", &N, &K);
    int n_stools = 0;
    double total_price = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &items[i].price, &items[i].type);
        items[i].original = i;
        total_price += items[i].price;

        if (items[i].type == STOOL)
            n_stools++;
    }

    sort(items, items + N);
    double save = 0;

    if (n_stools >= K)
    {
        int k = 0, done = N;

        for (int i = N - 1; i >= 0 && k < K - 1; i--)
            if (items[i].type == STOOL)
            {
                save += items[i].price;

                for (int j = i; j < done; j++)
                    carts[k].push_back(items[j].original);

                done = i;
                k++;
            }

        save += items[0].price;

        for (int i = 0; i < done; i++)
            carts[k].push_back(items[i].original);
    }
    else
    {
        int k = 0;

        for (int i = 0; i < N; i++)
            if (items[i].type == STOOL)
            {
                save += items[i].price;
                carts[k].push_back(items[i].original);
                k++;
            }

        assert(k == n_stools);

        for (int i = 0; i < N; i++)
            if (items[i].type == PENCIL)
            {
                carts[k].push_back(items[i].original);
                k++;

                if (k == K)
                    k = n_stools;
            }
    }

    printf("%.1lf\n", total_price - 0.5 * save);
    set<int> indices;

    for (int i = 0; i < K; i++)
    {
        printf("%d", (int) carts[i].size());

        for (int j = 0; j < (int) carts[i].size(); j++)
        {
            printf(" %d", carts[i][j] + 1);
            indices.insert(carts[i][j]);
        }

        printf("\n");
    }

    assert((int) indices.size() == N);
    return 0;
}