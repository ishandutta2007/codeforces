#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    long long first = A;
    long long second = min(B, C);
    long long jackets = D;
    long long total = 0;

    if (E > F) {
        long long make = min(first, jackets);
        first -= make;
        jackets -= make;
        total += make * E;
    } else {
        long long make = min(second, jackets);
        second -= make;
        jackets -= make;
        total += make * F;
    }

    total += min(first, jackets) * E;
    total += min(second, jackets) * F;
    cout << total << '\n';
}