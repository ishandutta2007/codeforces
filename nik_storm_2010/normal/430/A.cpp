#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 500;

int a[N], ans[N], l[N], r[N], n, m;

bool check()
{
    for (int j = 1; j <= m; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++) if (l[j] <= a[i] && a[i] <= r[j]) sum += ans[i];
        if (sum == 0) continue;
        if (sum == +1) continue;
        if (sum == -1) continue;
        return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d %d", &l[i], &r[i]);
    for (int i = 1; i <= n; i++)
    {
        int res = 1e9, nom = 0;
        for (int j = 1; j <= n; j++) if (ans[j] == 0 && a[j] < res) res = a[j], nom = j;
        ans[nom] = -1;
        if (check()) continue;
        ans[nom] = +1;
        if (check()) continue;
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) if (ans[i] == -1) printf("0 "); else printf("1 ");
    return 0;
}