#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

vector<int> g[100001];
vector<int> used;

int dfs(int v)
{
    used[v] = 1;
    for (auto u : g[v])
        if (!used[u])
            dfs(u);
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        g[k].push_back(i);
        g[i].push_back(k);
    }
    int num = 0;
    used.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            dfs(i);
            num++;
        }
    cout << num;
    return 0;
}