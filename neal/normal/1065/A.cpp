#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        long long S, A, B, C;
        scanf("%lld %lld %lld %lld", &S, &A, &B, &C);
        long long deals = S / (A * C);
        long long remaining = S - deals * A * C;
        long long bars = deals * (A + B) + remaining / C;
        printf("%lld\n", bars);
    }
}