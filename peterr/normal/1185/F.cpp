#include <bits/stdc++.h>

using namespace std;

const int MAXBIT = 1 << 9;
vector<pair<int, int>> pizzas[MAXBIT];
int friends[MAXBIT];

int countSat(int p1, int p2)
{
    int count = 0;
    int total = p1 | p2;
    for (int bit = 1; bit < MAXBIT; bit++)
    {
        if ((total & bit) == bit)
        {
            count += friends[bit];
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int bit = 0, f;
        cin >> f;
        for (int j = 0; j < f; j++)
        {
            int b;
            cin >> b;
            bit |= (1 << (b - 1));
        }
        friends[bit]++;
    }
    for (int i = 0; i < m; i++)
    {
        int cost, bit = 0, f;
        cin >> cost >> f;
        for (int j = 0; j < f; j++)
        {
            int b;
            cin >> b;
            bit |= (1 << (b - 1));
        }
        pizzas[bit].push_back({cost, i + 1});
    }
    for (int i = 0; i < MAXBIT; i++)
        sort(pizzas[i].begin(), pizzas[i].end());
    int maxSat = -1;
    int minCost = 2 * 1e9 + 5;
    pair<int, int> ans;
    for (int i = 1; i < MAXBIT; i++)
    {
        if (pizzas[i].empty())
            continue;
        for (int j = i; j < MAXBIT; j++)
        {
            if (pizzas[j].empty())
                continue;
            if (i == j)
            {
                if (pizzas[i].size() < 2)
                    continue;
                int sat = countSat(i, j);
                int cost = pizzas[i][0].first + pizzas[i][1].first;
                if (sat == maxSat)
                {
                    if (cost < minCost)
                    {
                        minCost = cost;
                        ans = {pizzas[i][0].second, pizzas[i][1].second};
                    }
                }
                else if (sat > maxSat)
                {
                    minCost = cost;
                    ans = {pizzas[i][0].second, pizzas[i][1].second};
                    maxSat = sat;
                }
            }
            else
            {
                int sat = countSat(i, j);
                int cost = pizzas[i][0].first + pizzas[j][0].first;
                if (sat == maxSat)
                {
                    if (cost < minCost)
                    {
                        minCost = cost;
                        ans = {pizzas[i][0].second, pizzas[j][0].second};
                    }
                }
                else if (sat > maxSat)
                {
                    minCost = cost;
                    ans = {pizzas[i][0].second, pizzas[j][0].second};
                    maxSat = sat;
                }
            }
        }
    }
    cout << ans.first << " " << ans.second;
    return 0;
}