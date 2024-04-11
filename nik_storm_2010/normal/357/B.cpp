#include<cstdio>
#include<memory.h>

using namespace std;

int color[100010];
bool used[10];

void make(int x) {
    if (color[x] != 0) return;
    for (int i = 1; i <= 3; i++) {
        if (used[i]) continue;
        color[x] = i;
        used[i] = true;
        return;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int c1, c2, c3;
        scanf("%d %d %d", &c1, &c2, &c3);
        memset(used, false, sizeof(used));
        used[color[c1]] = true;
        used[color[c2]] = true;
        used[color[c3]] = true;
        make(c1);
        make(c2);
        make(c3);
    }
    for (int i = 1; i <= n; i++) printf("%d ", color[i]);
    return 0;
}