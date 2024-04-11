#include <bits/stdc++.h>
using namespace std;

int n;
int a, x;

int main () {
    scanf("%d", &n);
    scanf("%d", &x);
    while ((x & 1) == 0) x >>= 1;
    while (x % 3 == 0) x /= 3;

    for (int i=1; i<n; i++) {
        scanf("%d", &a);
        while ((a & 1) == 0) a >>= 1;
        while (a % 3 == 0) a /= 3;

        if (a != x) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    return 0;
}