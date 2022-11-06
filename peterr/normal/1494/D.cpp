#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int par[MAXN + 1];
int sz[MAXN + 1];
int val[MAXN + 1];
int who[MAXN + 1];
int adj[MAXN + 1][MAXN + 1];
vector<int> salary;
vector<int> sup;

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

void mge(int x, int y, int cost)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    if (cost > max(val[x], val[y]))
    {
        salary.push_back(cost);
        sup.push_back(-1);
        sup[who[x]] = (int) salary.size() - 1;
        sup[who[y]] = (int) salary.size() - 1;
        who[y] = (int) salary.size() - 1;
        val[y] = cost;
    }
    else if (cost == val[x])
    {
        sup[who[y]] = who[x];
        val[y] = cost;
        who[y] = who[x];
    }
    else if (cost == val[y])
    {
        sup[who[x]] = who[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> events;
    salary = vector<int>(n + 1);
    sup = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = who[i] = i;
        sz[i] = 1;
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
            if (i == j)
                salary[i] = val[i] = adj[i][j];
            else if (i < j)
                events.push_back({adj[i][j], i, j});
        }
    }
    sort(events.rbegin(), events.rend());
    while (!events.empty())
    {
        /*
        int curSal = get<0>(events.back());
        while (!events.empty() && get<0>(events.back()) == curSal)
        {
            tuple<int, int, int> tup = events.back();
            events.pop_back();
        }
        */
        //cout << "loop " << endl;
        tuple<int, int, int> tup = events.back();
        events.pop_back();
        mge(get<1>(tup), get<2>(tup), get<0>(tup));
    }
    cout << salary.size() - 1 << "\n";
    for (int i = 1; i < (int) salary.size(); i++)
    {
        cout << salary[i] << " \n"[i == (int) salary.size() - 1];
    }
    cout << salary.size() - 1 << "\n";
    for (int i = 1; i < (int) sup.size() - 1; i++)
    {
        cout << i << " " << sup[i] << "\n";
    }
    return 0;
}