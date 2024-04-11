#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 10;

vector <int> ans[N];
int res;

void solve(int l, int r, int nom)
{
    res = max(res, nom);
    if (l == r) return;
    int m = (l + r) / 2;
    for (int i = l; i <= m; i++) ans[nom].push_back(i);
    solve(l, m, nom + 1);
    solve(m + 1, r, nom + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    solve(1, n, 0);
    printf("%d\n", res);
    for (int i = 0; i < res; i++)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}