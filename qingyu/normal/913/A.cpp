#include <bits/stdc++.h>

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    if (n > 30) printf("%d", m);
    else printf("%d", m % (1 << n));
    return 0;
}