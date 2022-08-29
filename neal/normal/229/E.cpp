#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

const int MAX = 1005;

int N, M, P, K[MAX];
vector<int> prices[MAX];
vector<int> all_prices;
double binom[MAX][MAX], save[MAX][MAX];

double expected(int n, int k, const vector<double> &nums)
{
    if (save[n][k] > -0.5)
        return save[n][k];

    if (n == 0 || k == 0)
        return 1;

    return save[n][k] = (double) k / n * nums[n - 1] * expected(n - 1, k - 1, nums) + (k < n ? (1 - (double) k / n) * expected(n - 1, k, nums) : 0);
}

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        binom[0][i] = 0;
        binom[i][0] = 1;
    }

    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];

    scanf("%d %d", &N, &M);
    P = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &K[i]);
        P += K[i];

        for (int j = 0; j < K[i]; j++)
        {
            int p;
            scanf("%d", &p);
            prices[i].push_back(p);
            all_prices.push_back(p);
        }

        sort(prices[i].rbegin(), prices[i].rend());
        assert(K[i] == (int) prices[i].size());
    }

    assert (P < MAX);
    sort(all_prices.rbegin(), all_prices.rend());
    int critical = all_prices[N - 1];
    int take = 0, all = 0;

    for (int i = 0; i < P; i++)
        if (all_prices[i] == critical)
        {
            take += i < N ? 1 : 0;
            all++;
        }

    double base_prob = 1;
    vector<double> mults;

    for (int i = 0; i < M; i++)
    {
        int base = 0, c_count = 0;

        for (int j = 0; j < K[i]; j++)
            if (prices[i][j] > critical)
                base++;
            else if (prices[i][j] == critical)
                c_count++;

        base_prob *= 1 / binom[K[i]][base];

        if (c_count > 0)
        {
            assert(c_count == 1);
            mults.push_back((base + 1.0) / (K[i] - base));
        }
    }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            save[i][j] = -1;

    printf("%.12lf\n", base_prob * expected(all, take, mults));
    return 0;
}