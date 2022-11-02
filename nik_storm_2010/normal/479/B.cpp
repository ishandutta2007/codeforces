#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;

vector <pii> a, b;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(make_pair(x, i));
    }
    for (int t = 1; t <= k; t++) {
        bool ok = true;
        for (int i = 0; i < n; i++) if (a[i].first != a[0].first) ok = false;
        if (ok) break;
        sort(a.begin(), a.end());
        b.push_back(make_pair(a[n - 1].second, a[0].second));
        a[n - 1].first--;
        a[0].first++;
    }
    sort(a.begin(), a.end());
    printf("%d %d\n", a[n - 1].first - a[0].first, b.size());
    for (int i = 0; i < b.size(); i++) printf("%d %d\n", b[i].first, b[i].second);
    return 0;
}