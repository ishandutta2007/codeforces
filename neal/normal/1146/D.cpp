#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int MAX = 1e5 + 5;

long long M, A, B;
vector<long long> min_mod, max_reached;

long long get_sum(long long n) {
    // Returns 0 / A + 1 / A + ... + (n - 1) / A.
    if (n <= 0)
        return 0;

    long long sum = 0;
    sum += (n % A) * (n / A);
    n -= n % A;
    sum += A * (n / A) * (n / A - 1) / 2;
    return sum;
}

int main() {
    cin >> M >> A >> B;
    min_mod.assign(A, INF);
    max_reached.assign(A, INF);
    min_mod[0] = max_reached[0] = 0;
    long long value = 0, reach = 0;

    while (true) {
        if (value < B) {
            long long add = (B - value + A - 1) / A;
            value += A * add;
            reach = max(reach, value);
        }

        value -= B;

        if (value >= min_mod[value % A])
            break;

        min_mod[value % A] = value;
        max_reached[value % A] = reach;
    }

    long long total = 0;

    for (int i = 0; i < A; i++)
        if (max_reached[i] <= M)
            total += (M - max_reached[i] + 1) + get_sum(M - min_mod[i] + 1) - get_sum(max_reached[i] - min_mod[i]);

    cout << total << '\n';
}