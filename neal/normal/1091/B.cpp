#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    long long x_sum = 0, y_sum = 0;

    for (int i = 0; i < 2 * N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x_sum += x;
        y_sum += y;
    }

    printf("%lld %lld\n", x_sum / N, y_sum / N);
}