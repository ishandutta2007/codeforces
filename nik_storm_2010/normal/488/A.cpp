#include <cstdio>

using namespace std;

bool good(int x) {
    if (x < 0) x = -x;
    for (; x != 0; x /= 10) if (x % 10 == 8) return true;
    return false;
}

int main() {
    int a;
    scanf("%d", &a);
    for (int b = 1; ; b++) if (good(a + b)) {
        printf("%d\n", b);
        break;
    }
    return 0;
}