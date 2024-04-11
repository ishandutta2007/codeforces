#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B, A;
    cin >> N >> B >> A;
    const int A_MAX = A;

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;

        if (A == 0 && B == 0) {
            cout << i << '\n';
            return 0;
        }

        if (S == 0) {
            if (A > 0)
                A--;
            else
                B--;
        } else if (S == 1) {
            if (A == A_MAX || B == 0) {
                A--;
            } else {
                B--;
                A++;
            }
        } else {
            assert(false);
        }
    }

    cout << N << '\n';
}