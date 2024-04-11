#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int a[N][N];
ll cost_n[M], cost_m[M];

int main()
{
    int n, m, k, p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    ll ans;
    priority_queue <ll> heap_n, heap_m;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++) sum += a[i][j];
        heap_n.push(sum);
    }
    for (int j = 1; j <= m; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += a[i][j];
        heap_m.push(sum);
    }
    ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += heap_n.top();
        heap_n.push(heap_n.top() - p * m);
        heap_n.pop();
        cost_n[i] = ans;
    }
    ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += heap_m.top();
        heap_m.push(heap_m.top() - p * n);
        heap_m.pop();
        cost_m[i] = ans;
    }
    ans = -1e18;
    for (int i = 0; i <= k; i++) ans = max(ans, cost_n[i] + cost_m[k - i] - 1LL * (k - i) * i * p);
    printf("%I64d\n", ans);
    return 0;
}