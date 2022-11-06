#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        if (n & 1) {
            printf("7");
            n -= 3;
        }
        for (; n; n -= 2) {
            printf("1");
        }
        printf("\n");
    }
    return 0;
}