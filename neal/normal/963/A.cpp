#include <iostream>
using namespace std;

// Create a namespace to avoid naming conflicts.
namespace neal {

const int MOD = 1000000009;

long long mod_pow(long long a, long long b) {
    long long p = 1;

    for (a %= MOD; b > 0; b >>= 1) {
        if (b & 1)
            p = p * a % MOD;

        a = a * a % MOD;
    }

    return p;
}

long long mod_inverse(long long a) {
    return mod_pow(a, MOD - 2);
}

long long N, A, B, K;
string sequence;

long long get_index(int i) {
    return (sequence[i % K] == '+' ? 1 : MOD - 1) * mod_pow(A, N - i) % MOD * mod_pow(B, i) % MOD;
}

void solve_problem() {
    cin >> N >> A >> B >> K;
    cin >> sequence;
    K = min(K, N + 1);

    long long sum_K = 0;

    for (int i = 0; i < K; i++)
        sum_K = (sum_K + get_index(i)) % MOD;

    long long repeats = (N + 1) / K;
    long long multiplier = mod_pow(mod_inverse(A), K) * mod_pow(B, K) % MOD;

    long long sum_N = sum_K * (1 - mod_pow(multiplier, repeats) + MOD) % MOD * mod_inverse(1 - multiplier + MOD) % MOD;

    if (multiplier == 1) {
        sum_N = sum_K * repeats % MOD;
    }

    for (int i = N + 1 - (N + 1) % K; i <= N; i++) {
        sum_N = (sum_N + get_index(i)) % MOD;
    }

    cout << sum_N << '\n';
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    neal::solve_problem();
    return 0;
}