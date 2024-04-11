#include <cstdio>
#include <vector>

using namespace std;
const int N = 5e3;

vector <int> edges[N];
int good[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
    }
    long long ans = 0;
    for (int finish = 1; finish <= n; finish++) {
        for (int i = 1; i <= n; i++) for (int j = 0; j < edges[i].size(); j++) {
            int to = edges[i][j];
            if (to == finish) {
                good[i] = finish;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i == finish) continue;
            long long cnt = 0;
            for (int j = 0; j < edges[i].size(); j++) {
                int to = edges[i][j];
                if (good[to] == finish) cnt++;
            }
            ans += (cnt * (cnt - 1)) / 2;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}