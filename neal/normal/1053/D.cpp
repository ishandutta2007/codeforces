#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> smallest_factor;
vector<bool> prime;

void sieve(int maximum) {
    assert(maximum > 0);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p <= maximum; p += 2) {
        prime[p] = p == 2;
        smallest_factor[p] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }

    for (int p = 2; p <= maximum; p++)
        if (prime[p])
            smallest_factor[p] = p;
}


int N, P_MAX;
vector<int> P;
vector<int> powers;
vector<int> reach_count;

bool add(int number, bool real = true) {
    bool helpful = false;

    while (number > 1) {
        int p = smallest_factor[number];
        int power = 0;

        do {
            number /= p;
            power++;
        } while (number % p == 0);

        if (!real) {
            helpful = helpful || power > powers[p];
            continue;
        }

        if (power > powers[p]) {
            powers[p] = power;
            helpful = true;
            reach_count[p] = 1;
        } else if (power == powers[p]) {
            reach_count[p]++;
        }
    }

    return helpful;
}

bool removable(int number) {
    bool ok = true;

    while (number > 1) {
        int p = smallest_factor[number];
        int power = 0;

        do {
            number /= p;
            power++;
        } while (number % p == 0);

        if (power == powers[p] && reach_count[p] == 1)
            ok = false;
    }

    return ok;
}

int main() {
    scanf("%d", &N);
    P.resize(N);
    P_MAX = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        P_MAX = max(P_MAX, P[i]);
    }

    sieve(P_MAX);
    powers.assign(P_MAX + 1, 0);
    reach_count.assign(P_MAX + 1, 0);
    sort(P.rbegin(), P.rend());

    vector<int> to_remove;
    bool add_one = false;

    for (int p : P)
        if (add(p, false)) {
            add(p);
        } else if (add(p - 1)) {
            to_remove.push_back(p - 1);
        } else {
            add_one = true;
        }

    for (int x : to_remove)
        if (removable(x))
            add_one = true;

    long long answer = 1;

    for (int i = 2; i <= P_MAX; i++)
        for (int j = 0; j < powers[i]; j++)
            answer = answer * i % MOD;

    if (add_one)
        answer = (answer + 1) % MOD;

    printf("%lld\n", answer);
}