#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) printf("%d %d\n", 4, n - 4); else printf("%d %d\n", 9, n - 9);
    return 0;
}