#include <cstdio>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int l = 1, r = n, side = 1;
    for (; k != 1; k--) if (side == 1) {
        printf("%d ", l);
        l++;
        side = 2;
    }
    else {
        printf("%d ", r);
        r--;
        side = 1;
    }
    if (side == 1) for (int i = l; i <= r; i++) printf("%d ", i); else for (int i = r; i >= l; i--) printf("%d ", i);
    printf("\n");
    return 0;
}