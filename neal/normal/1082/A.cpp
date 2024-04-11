#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

void solve_case() {
    int N, X, Y, D;
    scanf("%d %d %d %d", &N, &X, &Y, &D);
    X--; Y--;

    if (abs(X - Y) % D == 0) {
        printf("%d\n", abs(X - Y) / D);
        return;
    }

    int left = Y % D == 0 ? (X + D - 1) / D + Y / D : INF;
    X = N - 1 - X;
    Y = N - 1 - Y;
    int right = Y % D == 0 ? (X + D - 1) / D + Y / D : INF;
    int answer = min(left, right);
    printf("%d\n", answer < INF ? answer : -1);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}