#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> H(N);

    for (int &h : H)
        cin >> h;

    for (int i = 0; i < N - 1; i++) {
        int minimum = max(H[i + 1] - K, 0);

        if (H[i] > minimum) {
            M += H[i] - minimum;
        } else {
            M -= minimum - H[i];
        }

        if (M < 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}