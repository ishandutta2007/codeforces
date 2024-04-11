#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N, X;
    string S;
    cin >> N >> X >> S;
    int whole = 0;

    for (int i = 0; i < N; i++)
        whole += S[i] == '0' ? +1 : -1;

    int sum = 0, total = 0;

    for (int i = 0; i < N; i++) {
        if (whole == 0) {
            if (sum == X) {
                cout << -1 << '\n';
                return;
            }
        } else {
            int need = X - sum;

            if (need % whole == 0 && need / whole >= 0)
                total++;
        }

        sum += S[i] == '0' ? +1 : -1;
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}