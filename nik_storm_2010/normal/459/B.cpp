#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n && a[i] == a[0]; i++) k1++;
    for (int i = n - 1; i >= 0 && a[i] == a[n - 1]; i--) k2++;
    long long ans = (k1 == n) ? (1LL * k1 * (k1 - 1)) / 2 : 1LL * k1 * k2;
    printf("%d %I64d\n", a[n - 1] - a[0], ans);
    return 0;
}