#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1e6 + 5;
const int LOG = 20;
const int MOD = 998244353;

long long N;
long long mod_inv[N_MAX / 2];
long long pow3[N_MAX];
long long choose[N_MAX];

long long mod_pow_N(long long a) {
    long long result = 1;

    for (int i = 0; i < LOG; i++) {
        if (N & 1 << i)
            result = result * a % MOD;

        a = a * a % MOD;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    pow3[0] = 1;

    for (int i = 1; i <= N; i++) {
        pow3[i] = 3 * pow3[i - 1];

        if (pow3[i] >= MOD)
            pow3[i] -= MOD;

        if (pow3[i] >= MOD)
            pow3[i] -= MOD;
    }

    long long product = 1;

    for (int i = 0; i <= N / 2; i++) {
        mod_inv[i + 1] = i == 0 ? 1 : (MOD - MOD / (i + 1)) * mod_inv[MOD % (i + 1)] % MOD;
        choose[i] = choose[N - i] = product;
        product = product * (N - i) % MOD * mod_inv[i + 1] % MOD;
    }

    long long total = 0;
    long long pow_3N_N_rows = 1;

    for (int rows = N; rows > 0; rows--) {
        long long value = (3 * mod_pow_N(pow3[N - rows] - 1) + (2 * pow3[rows] - 3) * pow_3N_N_rows) % MOD * choose[rows];
        total = (total + (rows % 2 == 1 ? +1 : -1) * value) % MOD;
        pow_3N_N_rows = pow_3N_N_rows * pow3[N] % MOD;
    }

    total = (total % MOD + MOD) % MOD;
    cout << total << '\n';
    return 0;
}