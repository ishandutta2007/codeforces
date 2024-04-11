#include <bits/stdc++.h>
using namespace std;
int n;

void output(int x, int y) {
    if (n) {
        printf("%d %d\n", x, y);
        --n;
    }
}

int main() {
    scanf("%d", &n);
    output(0, 0);
    for (int i = 1; i <= 1000; ++i) {
        output(i, 0);
        output(0, i);
        output(-i, 0);
        output(0, -i);
    }
}