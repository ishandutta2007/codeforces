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
const int M = 200000;

int a[M];
vector <int> all[M];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    ll init = 0;
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= m; i++) init += abs(a[i] - a[i - 1]);
    for (int i = 1; i <= m; i++)
    {
        if (i != 1 && a[i] != a[i - 1]) all[a[i]].push_back(a[i - 1]);
        if (i != m && a[i] != a[i + 1]) all[a[i]].push_back(a[i + 1]);
    }
    ll ans = init;
    for (int i = 1; i <= n; i++)
    {
        int t = all[i].size();
        if (t == 0) continue;
        ll cur = init;
        sort(all[i].begin(), all[i].end());
        int be = all[i][t >> 1];
        for (int j = 0; j < t; j++) cur += -abs(i - all[i][j]) + abs(be - all[i][j]);
        ans = min(ans, cur);
    }
    printf("%I64d\n", ans);
    return 0;
}