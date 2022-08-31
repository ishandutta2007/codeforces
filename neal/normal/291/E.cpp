#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N_MAX = 100005, T_MAX = 300005;

int N, parent[N_MAX];
vector<int> children[N_MAX];
string T, edge[N_MAX];
int fail[T_MAX];
int total;

void prepare_fail()
{
    fail[0] = fail[1] = 0;

    for (int i = 1, p = 0; i < (int) T.length(); i++)
    {
        while (p > 0 && T[p] != T[i])
            p = fail[p];

        if (T[p] == T[i])
            p++;

        fail[i + 1] = p;
    }
}

void dfs(int node, int p)
{
    for (int i = 0; i < (int) edge[node].size(); i++)
    {
        while (p > 0 && T[p] != edge[node][i])
            p = fail[p];

        if (T[p] == edge[node][i])
            p++;

        if (p == (int) T.length())
        {
            total++;
            p = fail[p];
        }
    }

    for (int i = 0; i < (int) children[node].size(); i++)
        dfs(children[node][i], p);
}

int main()
{
    cin >> N;
    parent[0] = -1;

    for (int i = 1; i < N; i++)
    {
        cin >> parent[i] >> edge[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    cin >> T;
    prepare_fail();
    total = 0;
    dfs(0, 0);
    cout << total << '\n';
    return 0;
}