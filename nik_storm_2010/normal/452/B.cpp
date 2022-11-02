#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair <int, int> pii;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <pii> a;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        int dist = 1e9;
        dist = min(dist, (i - 0) * (i - 0) + (j - 0) * (j - 0));
        dist = min(dist, (i - 0) * (i - 0) + (j - m) * (j - m));
        dist = min(dist, (i - n) * (i - n) + (j - 0) * (j - 0));
        dist = min(dist, (i - n) * (i - n) + (j - m) * (j - m));
        if (dist <= 9) a.push_back(make_pair(i, j));
    }
    int p0, p1, p2, p3, k = a.size(), ans = 0;
    for (int i0 = 0; i0 < k; i0++) for (int i1 = 0; i1 < k; i1++) for (int i2 = 0; i2 < k; i2++) for (int i3 = 0; i3 < k; i3++) {
        if (i0 == i1 || i0 == i2 || i0 == i3 || i1 == i2 || i1 == i3 || i2 == i3) continue;
        int cur = 0;
        cur += pow(a[i0].first - a[i1].first, 2) + pow(a[i0].second - a[i1].second, 2);
        cur += pow(a[i1].first - a[i2].first, 2) + pow(a[i1].second - a[i2].second, 2);
        cur += pow(a[i2].first - a[i3].first, 2) + pow(a[i2].second - a[i3].second, 2);
        if (cur <= ans) continue;
        ans = cur;
        p0 = i0, p1 = i1, p2 = i2, p3 = i3;
    }
    printf("%d %d\n", a[p0].first, a[p0].second);
    printf("%d %d\n", a[p1].first, a[p1].second);
    printf("%d %d\n", a[p2].first, a[p2].second);
    printf("%d %d\n", a[p3].first, a[p3].second);
    return 0;
}