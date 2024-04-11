#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0) {
        int A, B, C, D, K;
        cin >> A >> B >> C >> D >> K;
        bool success = false;

        for (int X = 0; X <= K; X++) {
            int Y = K - X;

            if (X * C >= A && Y * D >= B) {
                success = true;
                cout << X << ' ' << Y << '\n';
                break;
            }
        }

        if (!success)
            cout << -1 << '\n';
    }
}