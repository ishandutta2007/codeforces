#include<cstdio>

using namespace std;

int main() {
    int x, n, k0, k5;
    k0 = k5 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) k0++; else k5++;
    }
    int p = k5 / 9;
    if (k0 == 0) { printf("-1"); return 0; }
    if (p == 0) { printf("0"); return 0; }
    for (int i = 1; i <= p * 9; i++) printf("5");
    for (int i = 1; i <= k0; i++) printf("0");
    return 0;
}