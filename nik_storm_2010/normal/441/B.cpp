#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 5000;

vector <int> num[N];
int fruits[N];

int main()
{
    int n, v;
    scanf("%d %d", &n, &v);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d %d", &x, &fruits[i]);
        num[x].push_back(i);
        num[x + 1].push_back(-i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        sort(num[i].begin(), num[i].end());
        int left = v;
        for (int j = 0; j < num[i].size(); j++)
        {
            if (num[i][j] < 0) num[i][j] *= -1;
            int take = min(left, fruits[num[i][j]]);
            left -= take;
            fruits[num[i][j]] -= take;
            ans += take;
        }
    }
    printf("%d\n", ans);
    return 0;
}