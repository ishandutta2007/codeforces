#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int move = min(K - 1, N - K) + N - 1;
    int stones = N + 1;
    cout << move + stones + N << '\n';
}