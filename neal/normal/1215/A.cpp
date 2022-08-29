#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A1, A2, K1, K2, N;
    cin >> A1 >> A2 >> K1 >> K2 >> N;

    if (K1 > K2) {
        swap(A1, A2);
        swap(K1, K2);
    }

    int take = A1 * (K1 - 1) + A2 * (K2 - 1);
    int minimum = max(N - take, 0);

    int maximum = 0;

    take = min(N / K1, A1);
    N -= take * K1;
    maximum += take;

    take = min(N / K2, A2);
    N -= take * K2;
    maximum += take;

    cout << minimum << ' ' << maximum << '\n';
}