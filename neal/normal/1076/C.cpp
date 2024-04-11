#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int D;
    scanf("%d", &D);

    if (D * D - 4 * D < 0) {
        puts("N");
        return;
    }

    double sum = D;
    double difference = sqrt(D * D - 4 * D);
    printf("Y %.12lf %.12lf\n", (sum + difference) / 2, (sum - difference) / 2);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}