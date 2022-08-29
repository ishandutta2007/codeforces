#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long A, B;
    cin >> A >> B;
    long long D = abs(A - B);
    long long moves = 0, sum = 0;

    while (sum < D || sum % 2 != D % 2)
        sum += ++moves;

    cout << moves << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}