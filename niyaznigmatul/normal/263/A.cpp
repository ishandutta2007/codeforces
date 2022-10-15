#include <cstdio>

int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int pi =-1, pj = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                pi = i;
                pj = j;
            }
        }
    }
    int i = 2, j = 2;
    printf("%d", abs(pi - i) + abs(pj - j));
}