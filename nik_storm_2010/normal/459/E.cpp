#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
const int N = 3e5 + 10;

vector <piii> e;
queue <pii> refresh;
int f[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        e.push_back(make_pair(-z, make_pair(x, y)));
    }
    sort(e.begin(), e.end());
    int l = 0;
    while (l < m) {
        int r = l;
        while (r < m && e[l].first == e[r].first) r++;
        for (int i = l; i < r; i++) {
            int x = e[i].second.first, y = e[i].second.second;
            refresh.push(make_pair(x, f[y] + 1));
        }
        while (refresh.empty() == false) {
            int x = refresh.front().first, y = refresh.front().second;
            refresh.pop();
            f[x] = max(f[x], y);
        }
        l = r;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}