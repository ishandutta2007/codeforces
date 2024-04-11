#include <bits/stdc++.h>

using namespace std;

int c[4], a[6];

void put(int i, int j) {
    int x = min(a[i], c[j]);
    a[i] -= x;
    c[j] -= x;
}

bool solve() {
    for(int i = 1; i <= 3; ++i) {
        put(i, i);
    }

    put(4, 1);
    put(4, 3);
    put(5, 2);
    put(5, 3);

    for(int i = 1; i <= 5; ++i)
        if (a[i] > 0)
            return false;
    return true;
}

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        for(int i = 1; i <= 3; ++i)
            scanf("%d", &c[i]);
        for(int i = 1; i <= 5; ++i)
            scanf("%d", &a[i]);

        puts(solve() ? "YES" : "NO");
    }

    return 0;
}