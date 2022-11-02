#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) ans += (2LL + i) * a[i];
    ans += 1LL * a[n - 1] * n;
    printf("%I64d\n", ans);
    return 0;
}