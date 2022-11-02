#include <cstdio>
#include <vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 100000;

vector <pii> ans[N];
int n, m, k;

void dfs(int x, int y, int cur)
{
    if (x > n) return;
    if (cur == 3 && k != 1) cur = 1, k--;
    ans[k].push_back(make_pair(x, y));
    if (x % 2)
    {
        y++;
        if (y == m + 1) x++, y = m;
        dfs(x, y, cur + 1);
    }
    else
    {
        y--;
        if (y == 0) x++, y = 1;
        dfs(x, y, cur + 1);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int need = k;
    dfs(1, 1, 1);
    for (int i = 1; i <= need; i++)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++) printf("%d %d ", ans[i][j].first, ans[i][j].second);
        printf("\n");
    }
    return 0;
}