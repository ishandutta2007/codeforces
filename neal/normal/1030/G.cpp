#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int P_MAX = 2e6 + 5;

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


int N;
vector<int> P;
vector<int> powers(P_MAX, 0);
vector<int> reach_count(P_MAX, 0);

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
    sieve(P_MAX);
    scanf("%d", &N);
    P.resize(N);
    map<int, int> P_freq;

    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        P_freq[P[i]]++;
    }

    for (auto it = P_freq.rbegin(); it != P_freq.rend(); it++)
        for (int k = 0; k < it->second; k++)
            if (add(it->first, false))
                add(it->first);
            else
                add(it->first - 1);

    bool add_one = false;

    for (auto it = P_freq.rbegin(); it != P_freq.rend(); it++)
        if (it->second >= 2 && removable(it->first - 1))
            add_one = true;

    long long answer = 1;

    for (int i = 2; i < P_MAX; i++)
        for (int j = 0; j < powers[i]; j++)
            answer = answer * i % MOD;

    if (add_one)
        answer = (answer + 1) % MOD;

    printf("%lld\n", answer);
}