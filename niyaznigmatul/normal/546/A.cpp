#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w;
    scanf("%d%d%d", &k, &n, &w);
    printf("%d\n", max(0, (w * (w + 1) / 2) * k - n));
}