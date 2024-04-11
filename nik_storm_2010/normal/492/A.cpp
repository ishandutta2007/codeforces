#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int x = 1, i = 1; ; i++, x += i) {
        n -= x;
        if (n < 0) {
            printf("%d\n", i - 1);
            break;
        }
    }
    return 0;
}