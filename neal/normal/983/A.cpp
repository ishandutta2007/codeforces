#include <algorithm>
#include <iostream>
using namespace std;

// Create a namespace to avoid naming conflicts.
namespace neal {

int N;
long long P, Q, B;

long long mult(long long a, long long b, long long mod) {
    a %= mod;
    b %= mod;
    long long result = 0;

    while (b > 0) {
        if (b & 1) {
            result += a;

            if (result >= mod)
                result -= mod;
        }

        a *= 2;

        if (a >= mod)
            a -= mod;

        b >>= 1;
    }

    return result % mod;
}

void solve_problem() {
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> P >> Q >> B;

        long long G = __gcd(P, Q);
        P /= G;
        Q /= G;

        for (int iters = 0; iters < 10; iters++) {
            B = mult(B, B, Q);
        }

        cout << (B % Q == 0 ? "Finite" : "Infinite") << '\n';
    }
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    neal::solve_problem();
    return 0;
}