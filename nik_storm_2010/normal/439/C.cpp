#include <cstdio>
#include <vector>

using namespace std;
const int N = 100000 + 10;

vector <int> ans[N], odd, even;

int main()
{
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x % 2) odd.push_back(x); else even.push_back(x);
    }
    int o1 = odd.size(), e1 = even.size();
    k -= p;
    for (int i = 1; i <= k; i++)
    {
        if (o1 == 0)
        {
            puts("NO");
            return 0;
        }
        ans[i].push_back(odd[--o1]);
    }
    for (int i = 1; i <= p; i++)
    {
        if (e1 == 0 && o1 < 2)
        {
            puts("NO");
            return 0;
        }
        if (e1 != 0) ans[i + k].push_back(even[--e1]); else
        {
            ans[i + k].push_back(odd[--o1]);
            ans[i + k].push_back(odd[--o1]);
        }
    }
    if (o1 % 2)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    while (o1 != 0) ans[1].push_back(odd[--o1]);
    while (e1 != 0) ans[1].push_back(even[--e1]);
    for (int i = 1; i <= k + p; i++)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}