#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int INF = 1000000000;
    int lower = -INF;
    int upper = INF;
    scanf("%d", &n);
    int offset = 0;
    for (int i = 0; i < n; i++) {
        int change;
        int current_div;
        scanf("%d %d", &change, &current_div);
        if (current_div == 1) {
            lower = max(lower, 1900 - offset);
        } else {
            upper = min(upper, 1900 - offset);
        }
        offset += change;
    }
    if (lower >= upper) {
        printf("Impossible\n");
    } else if (upper == INF) {
        printf("Infinity\n");
    } else {
        printf("%d\n", upper - 1 + offset);
    }
}