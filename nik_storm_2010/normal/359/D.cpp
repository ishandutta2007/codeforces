#include<cstdio>

using namespace std;
const int N = 300000 + 10;
const int M = 1000000 + 10;

int last[M], leng[M], res[N], ans, num;
bool have[M];

void modify(int j, int x, int i) {
    if (last[j] + 1 != i) {
        have[j] = false;
        leng[j] = 0;
    }
    leng[j]++;
    last[j] = i;
    if (x == j) have[j] = true;
    if (!have[j] || leng[j] < ans) return;
    if (leng[j] > ans) { num = 0; ans = leng[j]; }
    num++;
    res[num] = i - leng[j] + 1;
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 1; j * j <= x; j++) {
            if (x % j != 0) continue;
            modify(j, x, i);
            if (x / j != j) modify(x / j, x, i);
        }
    }
    printf("%d %d\n", num, ans - 1);
    for (int i = 1; i <= num; i++) printf("%d ", res[i]);
    return 0;
}