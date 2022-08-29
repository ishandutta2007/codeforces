#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int SEARCH = 100;

struct factorization {
    long long p, q;
    int power;
    bool is_pq;

    factorization(long long _p = -1, long long _q = -1, int _power = -1, bool _is_pq = false)
        : p(_p), q(_q), power(_power), is_pq(_is_pq) {}
};

int N;
vector<long long> numbers;
vector<factorization> solution;
set<long long> primes;

void find_prime_powers() {
    for (int i = 0; i < N; i++) {
        long double number = numbers[i];

        for (int power = 4; power >= 2; power--) {
            long long root = pow(number, 1.0 / power);
            bool done = false;

            for (long long p = max(root - SEARCH, 0LL); p <= root + SEARCH; p++) {
                long long product = 1;

                for (int it = 0; it < power; it++)
                    product *= p;

                if (product == numbers[i]) {
                    // cerr << numbers[i] << " is " << p << "**" << power << endl;
                    solution[i] = factorization(p, -1, power, false);
                    primes.insert(p);
                    done = true;
                    break;
                }
            }

            if (done)
                break;
        }

        if (solution[i].p == -1)
            solution[i].is_pq = true;
    }
}

void solve_pq() {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            long long g = __gcd(numbers[i], numbers[j]);

            if (g > 1 && g < min(numbers[i], numbers[j]))
                primes.insert(g);
        }

    for (int i = 0; i < N; i++)
        if (solution[i].is_pq)
            for (long long p : primes)
                if (numbers[i] % p == 0) {
                    solution[i] = factorization(p, numbers[i] / p, 1, true);
                    break;
                }
}

const int MOD = 998244353;

long long solve_answer() {
    long long answer = 1;
    map<long long, int> powers;
    vector<bool> skip(N, false);

    for (int i = 0; i < N; i++) {
        if (skip[i])
            continue;

        if (solution[i].p == -1) {
            int same = 0;

            for (int j = 0; j < N; j++)
                if (numbers[j] == numbers[i]) {
                    same++;
                    skip[j] = true;
                }

            answer = answer * (same + 1) * (same + 1) % MOD;
        } else {
            powers[solution[i].p] += solution[i].power;

            if (solution[i].q != -1)
                powers[solution[i].q]++;
        }
    }

    for (auto &entry : powers)
        answer = answer * (entry.second + 1) % MOD;

    return (answer % MOD + MOD) % MOD;
}

int main() {
    cin >> N;
    numbers.resize(N);
    solution.resize(N);

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    find_prime_powers();
    solve_pq();
    cout << solve_answer() << endl;
}