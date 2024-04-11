#include <bits/stdc++.h>

int a, b, c, d;

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", ((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d)));
    return 0;
}