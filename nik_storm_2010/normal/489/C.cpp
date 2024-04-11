#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e3;

int a[N], b[N];

int main() {
    int m, s;
    scanf("%d %d", &m, &s);
    if (m == 1) {
        if (s <= 9) printf("%d %d", s, s); else printf("-1 -1");
        return 0;
    }
    if (s == 0 || s > 9 * m) {
        printf("-1 -1");
        return 0;
    }
    int sum = s;
    for (int i = 1; i <= m; i++) {
        int add = min(9 - a[i], sum);
        a[i] += add;
        sum -= add;
    }
    sum = s - 1, b[1] = 1;
    for (int i = m; i >= 1; i--) {
        int add = min(9 - b[i], sum);
        b[i] += add;
        sum -= add;
    }
    for (int i = 1; i <= m; i++) printf("%d", b[i]);
    printf(" ");
    for (int i = 1; i <= m; i++) printf("%d", a[i]);
    return 0;
}