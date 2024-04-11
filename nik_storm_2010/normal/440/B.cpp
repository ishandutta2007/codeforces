#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
const int N = 1e5;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll sum = 0, cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    sum /= n;
    for (int i = 1; i <= n; i++)
    {
        cur = cur - a[i] + sum;
        ans += abs(cur);
    }
    printf("%I64d\n", ans);
    return 0;
}