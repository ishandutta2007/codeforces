#include<cstdio>

using namespace std;

int main() {
    int n, k1, k2;
    scanf("%d", &n);
    k1 = k2 = 0;
    for (int i = 0; i < n; i++) {
        int weight;
        scanf("%d", &weight);
        if (weight == 25) { k1++; continue; }
        if (weight == 50) {
            if (k1 == 0) { printf("%s", "NO"); return 0; };
            k1--;
            k2++;
        }
        else {
            if (k1 != 0 && k2 != 0) {
                k1--;
                k2--;
                continue;
            }
            if (k1 >= 3) {
                k1 -= 3;
                continue;
            }
            printf("%s", "NO");
            return 0;
        }
    }
    printf("%s", "YES");
    return 0;
}