#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    a.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i -= k) ans += 2 * (a[i] - 1);
    printf("%d\n", ans);
    return 0;
}