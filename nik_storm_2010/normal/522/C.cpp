#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5;
const int INF = 2e9;

int a[N], b[N], type[N], r[N];
char pr[N];

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; t++) {
        int m, k;
        scanf("%d %d", &m, &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
            b[i] = 0;
            pr[i] = '?';
        }
        for (int i = 1; i < m; i++) {
            scanf("%d %d", &type[i], &r[i]);
            b[type[i]]++;
        }
        bool was = false;
        int cnt = 0;
        for (int i = 1; i < m; i++) {
            if (r[i] == 1) {
                if (!was) {
                    was = true;
                    int num = INF;
                    for (int j = 1; j <= k; j++) {
                        if (b[j] != 0) {
                            continue;
                        }
                        num = min(num, a[j]);
                        if (a[j] <= cnt) {
                            pr[j] = 'Y';
                        }
                    }
                    cnt -= num;
                }
            }
            if (type[i] == 0) {
                cnt++;
            } else {
                a[type[i]]--;
                b[type[i]]--;
            }
        }
        for (int i = 1; i <= k; i++) {
            if (pr[i] != '?') {
                continue;
            }
            pr[i] = (a[i] <= cnt ? 'Y' : 'N');
        }
        for (int i = 1; i <= k; i++) {
            printf("%c", pr[i]);
        }
        printf("\n");
    }
    return 0;
}