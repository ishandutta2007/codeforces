#include<cstdio>
#include<vector>
#include<set>

using namespace std;
const int N = 300000;

vector <int> ver[N];
set <int> edges[N];
int cur;

bool dfs(int x, int prev)
{
    int mom = cur++;
    while (true)
    {
        set <int>::iterator it = edges[x].begin();
        if (it == edges[x].end()) break;
        int y = (*it);
        edges[x].erase(edges[x].find(y));
        edges[y].erase(edges[y].find(x));
        bool res = dfs(y, x);
        if (!res) ver[mom].push_back(y);
    }
    int i;
    for (i = 0; i + 1 < ver[mom].size(); i += 2) printf("%d %d %d\n", ver[mom][i], x, ver[mom][i + 1]);
    if (i == ver[mom].size()) return false;
    printf("%d %d %d\n", ver[mom][i], x, prev);
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].insert(y);
        edges[y].insert(x);
    }
    if (m % 2 == 1) printf("No solution\n"); else dfs(1, 1);
    return 0;
}