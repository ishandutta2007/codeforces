#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    vector <int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * x * a[i];
        if (x != 1) x--;
    }
    printf("%I64d\n", ans);
    return 0;
}