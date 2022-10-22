#include <bits/stdc++.h>
using namespace std;
inline int Ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int tmp;
    // tmp = abs(x - 2000) + abs(y - 100);
    scanf("%d", &tmp);
    return tmp;
}
int main() {
    int u = Ask(1, 1e9);
    int v = Ask(1, 1);
    int Y;
    if (u > v) {
        int L = 1, H = 1e9 - (u - v);
        Y = (L + H) >> 1;
    } else {
        int L = 1 + (v - u), H = 1e9;
        Y = (L + H) >> 1;
    }
    int a = 1 + Ask(1, Y), b = v + 2 - a;
    int c = 1e9 - Ask(1e9, Y), d = (long long)(2e9) - Ask(1e9, 1e9) - c;
    printf("! %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    return 0;
}