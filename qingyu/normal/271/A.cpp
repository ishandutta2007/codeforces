#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    while (true) {
        ++n;
        int a = n % 10, b = (n / 10) % 10, c = (n / 100) % 10, d = n / 1000;
        if (a != b && a != c && a != d && b != c && b != d && c != d) return printf("%d", n), 0;
    }
}