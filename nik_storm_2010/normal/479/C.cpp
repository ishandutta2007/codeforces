#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;

int main() {
    int n;
    scanf("%d", &n);
    vector <pii> base(n);
    for (int i = 0; i < n; i++) scanf("%d %d", &base[i].first, &base[i].second);
    sort(base.begin(), base.end());
    int ans = 0;
    for (int i = 0; i < n; i++) if (base[i].second >= ans) ans = base[i].second; else ans = base[i].first;
    printf("%d\n", ans);
    return 0;
}