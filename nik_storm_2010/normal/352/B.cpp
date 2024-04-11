#include<cstdio>

using namespace std;
const int N = 100000 + 100;

int p[N], step[N];

int main() {
    int n, x;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        if (p[x] == 0) ans++;
        else {
            if (step[x] == 0) step[x] = i - p[x];
            else {
                if (step[x] == -1) continue;
                if (i - p[x] != step[x]) {
                    step[x] = -1;
                    ans--;
                }
            }
        }
        p[x] = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= N; i++)
        if (p[i] != 0 && step[i] != -1) printf("%d %d\n", i, step[i]);
    return 0;
}