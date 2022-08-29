#include <iostream>
using namespace std;

const int N_MAX = 505, MOD = 1e9 + 7;

int N, potential[N_MAX];

int main() {
    cin >> N;
    long long answer = 0;

    for (int i = 1; i < N; i++)
        answer = (2 * answer + 1) % MOD;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a >= 0) {
            answer -= potential[a] + 1;
            potential[a] = (2 * potential[a] + 1) % MOD;
        }
    }

    cout << (answer % MOD + MOD) % MOD << '\n';
}