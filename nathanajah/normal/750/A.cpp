#include <bits/stdc++.h>
using namespace std;

int n, k;
int main() {
    scanf("%d %d", &n, &k);
    k = 240 - k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (k >= 5*i) {
            k -= 5*i;
            res++;
        }
    }
    printf("%d\n", res);
}