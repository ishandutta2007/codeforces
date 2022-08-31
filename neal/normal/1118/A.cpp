#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    while (Q-- > 0) {
        long long N, A, B;
        cin >> N >> A >> B;
        cout << min(N * A, N / 2 * B + N % 2 * A) << '\n';
    }
}