#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (i * a + b * j == c) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
}