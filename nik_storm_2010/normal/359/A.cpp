#include<cstdio>

using namespace std;

int main() {
    int n, m, x;
    scanf("%d %d", &n, &m);
    bool good = false;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", &x);
        if (x == 0) continue;
        if (i == 1 || i == n || j == 1 || j == m) good = true;
    }
    if (good) printf("2"); else printf("4");
    return 0;
}