#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while (T--) {
        int N, Z;
        scanf("%d%d", &N, &Z);
        int mx = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            mx = max(mx, x);
            mx = max(mx, x | Z);
        }
        printf("%d\n", mx);
    }
}