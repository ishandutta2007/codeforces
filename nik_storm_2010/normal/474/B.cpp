#include <cstdio>

using namespace std;
const int N = 1e6 + 10;

int ans[N];

int main() {
    int n, last = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int cnt;
        scanf("%d", &cnt);
        while (cnt != 0) ans[++last] = i, cnt--;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int ask;
        scanf("%d", &ask);
        printf("%d\n", ans[ask]);
    }
    return 0;
}