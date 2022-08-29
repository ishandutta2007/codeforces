#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int angle;
    scanf("%d", &angle);
    int answer = 180 / __gcd(180, angle);

    if (180 - angle == 180 / answer)
        answer *= 2;

    printf("%d\n", answer);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}