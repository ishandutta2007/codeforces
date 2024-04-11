#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int s = n + m;
    if (n < m) n = m;
    printf("%d %d\n", n - 1, s - n);
}