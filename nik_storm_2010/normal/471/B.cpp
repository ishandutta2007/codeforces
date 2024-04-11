#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 5e3;

int a[N], nom[N], x[N], y[N], z[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), nom[i] = i;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (a[i] > a[j]) swap(a[i], a[j]), swap(nom[i], nom[j]);
    int equal = 0;
    for (int i = 2; i <= n; i++) if (a[i] == a[i - 1]) equal++;
    if (equal < 2) {
        puts("NO");
        return 0;
    }
    int state = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i - 1] != a[i] || state == 2) {
            x[i] = y[i] = z[i] = nom[i];
            continue;
        }
        if (state == 0) {
            x[i] = x[i - 1];
            x[i - 1] = y[i] = z[i] = nom[i];
            state = 1;
            continue;
        }
        y[i] = y[i - 1];
        x[i] = y[i - 1] = z[i] = nom[i];
        state = 2;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", x[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", y[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", z[i]);
    printf("\n");
    return 0;
}