#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

bool attempt(double x) {
    double minA = (double)A - abs(x);
    double maxA = (double)A + abs(x);
    double minB = (double)B - abs(x);
    double maxB = (double)B + abs(x);
    double minC = (double)C - abs(x);
    double maxC = (double)C + abs(x);
    double minD = (double)D - abs(x);
    double maxD = (double)D + abs(x);

    double minAD = min(min(minA * minD, maxA * minD), min(minA * maxD, maxA * maxD));
    double maxAD = max(max(minA * minD, maxA * minD), max(minA * maxD, maxA * maxD));
    double minCB = min(min(minB * minC, maxB * minC), min(minB * maxC, maxB * maxC));
    double maxCB = max(max(minB * minC, maxB * minC), max(minB * maxC, maxB * maxC));

    if (minAD - maxCB <= 0 && maxAD - minCB >= 0) return 1;
    else return 0;
}

int main() {
    scanf("%d%d%d%d", &A, &B, &C, &D);
    int count = 0;
    double mini = 0.0, maxi = 100000000000.0, mid;
    while (true) {
        count++;
        if (maxi - mini < 1e-09 || count >= 50000) {
            printf("%.9lf\n", mini);
            return 0;
        }
        else if (attempt((mini + maxi) / 2)) maxi = (mini + maxi) / 2;
        else mini = (mini + maxi) / 2;
    }
}