#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


const int N = 5010;

long long F;
long long freq[N + 1], prefix_freq[N + 2];
long long factorial_primes[N + 1];

bool good(long long count) {
    return count > F / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(N);
    cin >> F;

    for (int i = 0; i < F; i++) {
        int k;
        cin >> k;
        freq[k]++;
    }

    prefix_freq[0] = 0;

    for (int i = 0; i <= N; i++)
        prefix_freq[i + 1] = prefix_freq[i] + freq[i];

    factorial_primes[0] = 0;

    for (int i = 1; i <= N; i++) {
        factorial_primes[i] = factorial_primes[i - 1];
        int x = i;

        while (x > 1) {
            factorial_primes[i]++;
            x /= smallest_factor[x];
        }
    }

    long long total = 0;

    for (int i = 1; i <= N; i++)
        total += freq[i] * factorial_primes[i];

    int start_prime = -1;

    for (int index = 0; index < (int) primes.size() - 1; index++)
        if (good(prefix_freq[primes[index + 1]] - prefix_freq[primes[index]])) {
            start_prime = index;
            break;
        }

    if (start_prime < 0) {
        cout << total << '\n';
        return 0;
    }

    dbg(total);
    int start = primes[start_prime], end = primes[start_prime + 1];

    for (int p = start_prime; p >= 0; p--) {
        int my_prime = primes[p];

        while (start < end && freq[end - 1] == 0)
            end--;

        dbg(my_prime, start, end);

        if (!good(prefix_freq[end] - prefix_freq[start]))
            break;

        vector<int> starts;

        for (int i = start; i < end; i++)
            if (i == start || i % my_prime == 0)
                starts.push_back(i);

        // dbg(starts);

        int index = 0;
        long long previous_power = 0;

        while (index < (int) starts.size() && good(prefix_freq[end] - prefix_freq[starts[index]])) {
            long long x = starts[index], power = 0;

            while (x >= my_prime) {
                power += x / my_prime;
                x /= my_prime;
            }

            dbg(power);
            total -= (power - previous_power) * (2 * (prefix_freq[end] - prefix_freq[starts[index]]) - F);
            previous_power = power;
            dbg(total);
            index++;
        }

        starts.push_back(end);
        bool found = false;

        for (index = 0; index < (int) starts.size() - 1; index++)
            if (good(prefix_freq[starts[index + 1]] - prefix_freq[starts[index]])) {
                start = starts[index];
                end = starts[index + 1];
                found = true;
                break;
            }

        if (!found || !good(prefix_freq[end] - prefix_freq[start]))
            break;
    }

    cout << total << '\n';
}