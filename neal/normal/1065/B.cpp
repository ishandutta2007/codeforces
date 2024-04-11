#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    long long minimum = max(N - 2 * M, 0LL);
    long long maximum = 0;

    while (N >= 0 && N * (N - 1) / 2 >= M) {
        N--;
        maximum++;
    }

    maximum--;
    cout << minimum << ' ' << maximum << '\n';
}