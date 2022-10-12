#include<cstdio>

int n, m;

int main() {
    scanf("%d %d", &n, &m);

    if (n == 1) {
        puts("1");
        return 0;
    }

    if (m > n / 2) printf("%d\n", m-1);
    else printf("%d\n", m+1);
}