#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

long long mod_inv(long long a, long long m = MOD) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

int mod_add(int a, int b) {
    int sum = a + b;
    return sum >= MOD ? sum - MOD : sum;
}

int mod_sub(int a, int b) {
    int diff = a - b;
    return diff < 0 ? diff + MOD : diff;
}

// Note: can change these to int to save memory, but beware of overflow.
vector<int> factorial, inv_factorial;
vector<int> inv;

void prepare_factorials(int max) {
    inv.assign(max + 1, 1);

    for (int i = 2; i <= max; i++)
        inv[i] = (long long) inv[MOD % i] * (MOD - MOD / i) % MOD;

    factorial.resize(max + 1);
    inv_factorial.resize(max + 1);
    factorial[0] = inv_factorial[0] = 1;

    for (int i = 1; i <= max; i++) {
        factorial[i] = (long long) i * factorial[i - 1] % MOD;
        inv_factorial[i] = (long long) inv[i] * inv_factorial[i - 1] % MOD;
    }
}

long long choose(int n, int r) {
    assert(0 <= r && r <= n);
    return (long long) factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD;
}

long long ways_to_distribute(int score, int players) {
    if (score <= 0 || players <= 0)
        return score == 0 ? 1 : 0;

    return choose(score + players - 1, score);
}

// Counts the number of ways to distribute sum points to players such that they are all < me
long long ways_to_distribute_bounded(int players, int me, int sum) {
    int total = 0;

    for (int p = 0; p <= players; p++) {
        int ways = choose(players, p) * ways_to_distribute(sum - me * p, players) % MOD;

        if (p % 2 == 0)
            total = mod_add(total, ways);
        else
            total = mod_sub(total, ways);
    }

    return total;
}

int main() {
    int P, S, R;
    cin >> P >> S >> R;
    prepare_factorials(S + P);

    if (P == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (S == 0) {
        cout << inv[P] << '\n';
        return 0;
    }

    long long total = 0, denominator = 0;

    for (int me = R; me <= S; me++) {
        long long ways = ways_to_distribute(S - me, P - 1);
        denominator = (denominator + ways) % MOD;

        if (me > S - me) {
            total = (total + ways) % MOD;
            continue;
        }

        if (me * P < S)
            continue;

        int max_same = S / me;
        assert(max_same >= 2 && max_same <= P);

        for (int same = max_same; same > 0; same--) {
            // Count ways to distribute S - same * me points to P - same players where everybody < me
            long long less_than = ways_to_distribute_bounded(P - same, me, S - same * me);
            total = (total + less_than * choose(P - 1, same - 1) % MOD * inv[same]) % MOD;
        }
    }

    total %= MOD;
    total = total * mod_inv(denominator) % MOD;
    cout << total << '\n';
}