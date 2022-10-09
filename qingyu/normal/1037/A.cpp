#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (int)ceil(log2(n * 1.0 + 1)));
    return 0;
}