#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> smallest_factor;
vector<int> totient;
vector<bool> prime;
vector<int> primes;

// Note: This sieve is O(n), but the constant factor is worse than the O(n log log n) sieve due to the multiplication.
void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    totient.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    totient[1] = 1;
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i++) {
        if (prime[i]) {
            smallest_factor[i] = i;
            totient[i] = i - 1;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > smallest_factor[i] || i * p > maximum)
                break;

            prime[i * p] = false;
            smallest_factor[i * p] = p;
            totient[i * p] = smallest_factor[i] == p ? p * totient[i] : (p - 1) * totient[i];
        }
    }
}


int main() {
    int N, K;
    cin >> N >> K;
    sieve(N);

    if (K == 1) {
        cout << 3 << '\n';
        return 0;
    }

    vector<int> freq(N + 1, 0);

    for (int i = 3; i <= N; i++)
        freq[totient[i]]++;

    long long total = 2;
    int count = 0;

    for (int i = 0; i <= N && count < K; i++)
        while (freq[i] > 0 && count < K) {
            total += i;
            freq[i]--;
            count++;
        }

    cout << total << '\n';
}