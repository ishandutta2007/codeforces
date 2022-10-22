#include <bits/stdc++.h>
using namespace std;

int N, M;

bool attempt(int x) {
    if (x == -1) return false;
    int ns = x / 2, ms = x / 3, is = x / 6;
    int n = N, m = M;
    n -= ns - is;
    m -= ms - is;
    n = max(0, n);
    m = max(0, m);
    return is >= n + m;
}

int main() {
    scanf("%d%d", &N, &M);
    int bot = -1, top = 10000000, mid;
    while (bot + 1 < top) {
        mid = (bot + top) / 2;
        if (attempt(mid)) top = mid;
        else bot = mid;
    }
    printf("%d\n", bot + 1);
}