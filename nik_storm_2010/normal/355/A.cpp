#include<cstdio>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        if (n == 1) printf("0"); else printf("No solution");
        return 0;
    }
    printf("%d", k);
    for (int i = 1; i < n; i++) printf("0");
    return 0;
}