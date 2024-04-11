#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    long long A = sqrt(2 * (N + K)) - 1;
    cout << N - A << '\n';
}