#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    int jump = K;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        jump = __gcd(jump, A);
    }

    cout << K / jump << '\n';

    for (int k = 0; k < K; k += jump)
        cout << k << ' ';

    cout << '\n';
    return 0;
}