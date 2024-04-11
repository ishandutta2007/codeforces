#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int packets = 0, sum = 0;

    while (sum < N) {
        sum += 1 << packets;
        packets++;
    }

    cout << packets << '\n';
}