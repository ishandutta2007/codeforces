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

    while (N-- > 0) {
        long long K;
        int X;
        cin >> K >> X;
        cout << 9 * (K - 1) + X << '\n';
    }
}