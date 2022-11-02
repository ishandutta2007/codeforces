#include <cstdio>

using namespace std;

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int sum = a + b + c + d + e;
    if (sum % 5 != 0 || sum == 0) puts("-1"); else printf("%d\n", sum / 5);
    return 0;
}