#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int L, R;
    scanf("%d %d", &L, &R);
    printf("%d %d\n", L, 2 * L);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}