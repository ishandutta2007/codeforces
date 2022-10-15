#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[123456];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    int mm = 1 << 31;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mm > a[i].second) ++ans; else
                mm = a[i].second;
    }
    printf("%d\n", ans);
}