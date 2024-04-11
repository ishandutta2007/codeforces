#include <cstdio>

using namespace std;

int main() {
    int n, start;
    scanf("%d", &n);
    if (n <= 3) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if (n % 2 == 0) {
        start = 5;
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }
    else {
        start = 6;
        printf("3 - 2 = 1\n");
        printf("1 + 5 = 6\n");
        printf("1 * 4 = 4\n");
        printf("6 * 4 = 24\n");
    }
    for (int i = start; i <= n; i += 2) {
        printf("%d - %d = 1\n", i + 1, i);
        printf("1 * 24 = 24\n");
    }
    return 0;
}