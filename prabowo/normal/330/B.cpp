#include <bits/stdc++.h>
using namespace std;

int n, m;
bool uda[1002];

int main () {
    scanf("%d %d", &n, &m);

    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        uda[u-1] = uda[v-1] = 1;
    }

    for (int i=0; i<n; i++) if (!uda[i]) {
        printf("%d\n", n-1);
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            printf("%d %d\n", i+1, j+1);
        }
        break;
    }

    return 0;
}