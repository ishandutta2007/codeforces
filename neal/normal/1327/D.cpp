#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<long long, int>> prime_factorize(long long n) {
    long long sieve_max = (long long) smallest_factor.size() - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<long long, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            long long p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (long long p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

// http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;

long long factors[FACTORS_MAX];

int generate_factors(const vector<pair<long long, int>> &prime_factors, bool sorted = false) {
    static long long buffer[FACTORS_MAX];
    int f_size = 0;
    factors[f_size++] = 1;

    for (auto &pf : prime_factors) {
        long long p = pf.first;
        int exponent = pf.second;
        int before_size = f_size;

        for (int e = 1; e <= exponent; e++)
            for (int i = 0; i < before_size; i++) {
                factors[f_size] = factors[f_size - before_size] * p;
                f_size++;
            }

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < f_size; section *= 2)
                for (int i = 0; i + section < f_size; i += 2 * section) {
                    int length = min(2 * section, f_size - i);
                    merge(factors + i, factors + i + section, factors + i + section, factors + i + length, buffer);
                    copy(buffer, buffer + length, factors + i);
                }
    }

    return f_size;
}


int N;
vector<int> P, C;

void run_case() {
    cin >> N;
    sieve(N);
    P.resize(N);
    C.resize(N);

    for (int &p : P) {
        cin >> p;
        p--;
    }

    for (int &c : C) {
        cin >> c;
        c--;
    }

    vector<bool> cycle_done(N, false);
    int best = N;

    for (int start = 0; start < N; start++)
        if (!cycle_done[start]) {
            vector<int> cycle;

            for (int i = start; !cycle_done[i]; i = P[i]) {
                cycle_done[i] = true;
                cycle.push_back(C[i]);
            }

            int n = cycle.size();
            int f_size = generate_factors(prime_factorize(n));

            for (int f = 0; f < f_size; f++) {
                int factor = factors[f];

                if (factor < best) {
                    for (int first = 0; first < factor; first++) {
                        bool works = true;

                        for (int i = first; i < n; i += factor)
                            if (cycle[i] != cycle[first]) {
                                works = false;
                                break;
                            }

                        if (works) {
                            best = factor;
                            break;
                        }
                    }
                }
            }
        }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}