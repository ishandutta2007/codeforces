#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 60;
const long long BOUND = 2e16 + 5;

int N;
long long X[N_MAX], Y[N_MAX];
long long AX, AY, BX, BY;
long long XS, YS, T;

long long start_distance(int index) {
    return abs(XS - X[index]) + abs(YS - Y[index]);
}

long long get_distance(int index1, int index2) {
    return abs(X[index1] - X[index2]) + abs(Y[index1] - Y[index2]);
}

int main() {
    cin >> X[0] >> Y[0] >> AX >> AY >> BX >> BY;
    cin >> XS >> YS >> T;
    N = 0;

    while (X[N] <= BOUND && Y[N] <= BOUND) {
        N++;
        X[N] = AX * X[N - 1] + BX;
        Y[N] = AY * Y[N - 1] + BY;
    }

    int best = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j <= N; j++)
            for (int first = i; first < j; first++) {
                long long distance1 = start_distance(first);
                long long distance2 = distance1;

                for (int k = first - 1; k >= i; k--)
                    distance1 += get_distance(k + 1, k);

                for (int k = first + 1; k < j; k++)
                    distance1 += get_distance(k == first + 1 ? i : k - 1, k);

                for (int k = first + 1; k < j; k++)
                    distance2 += get_distance(k - 1, k);

                for (int k = first - 1; k >= i; k--)
                    distance2 += get_distance(k == first - 1 ? j - 1 : k + 1, k);

                if (min(distance1, distance2) <= T)
                    best = max(best, j - i);
            }

    cout << best << '\n';
}