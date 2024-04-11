#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10 + 5;

int T, N, a[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        printf(a[1] == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}