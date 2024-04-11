#include <bits/stdc++.h>

using namespace std;

int N, K, ans_sg;

int get_sg(int x) {
    if (K & 1) {
        if (x <= 3) return x & 1;
        else if (x == 4) return 2;
        else if (x & 1) return 0;
        else return get_sg(x >> 1) == 1 ? 2 : 1;
    } else {
        if (x <= 2) return x;
        else return ~x & 1;
    }
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1, x; i <= N; i ++) {
        scanf("%d", &x);
        ans_sg ^= get_sg(x);
    }
    printf(ans_sg ? "Kevin\n" : "Nicky\n");
    fprintf(stderr, "%d\n", ans_sg);
    return 0;
}