#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, w = 0, h = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char type;
        int x, y;
        scanf(" %c %d %d", &type, &x, &y);

        if (x > y)
            swap(x, y);

        if (type == '+') {
            w = max(w, x);
            h = max(h, y);
        } else {
            puts(w <= x && h <= y ? "YES" : "NO");
        }
    }
}