#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
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

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


const int SIEVE = 10000;
const int QUERIES = 22;
const int X_LIMIT = 1e9;
const int64_t Q_LIMIT = 1e18;

// Query 2 * 3 * 5 * 7 * ... to find all the primes that X contains.
// Each time we find a prime p, we need to query the largest power of p <= current max X. After we query those, divide
// out all powers to get a new max X.
//

int queries, X_max;
vector<bool> has_prime;
set<int> needs_query;
map<int, int> X_primes;

bool exceeds_limit(int64_t a, int64_t b) {
    return (long double) a * b > Q_LIMIT;
}

int64_t build_power(int p) {
    int64_t product = 1;

    while (product * p <= X_LIMIT)
        product *= p;

    return product;
}

void query(int64_t q);

void do_needed_queries(bool two = true) {
    while (!needs_query.empty() && queries < QUERIES && (needs_query.size() >= 2 || !two)) {
        int64_t product = build_power(*needs_query.begin());
        needs_query.erase(needs_query.begin());

        if (!needs_query.empty()) {
            product *= build_power(*needs_query.begin());
            needs_query.erase(needs_query.begin());
        }

        query(product);
    }
}

void query(int64_t q) {
    queries++;
    cout << "? " << q << endl;
    int64_t g;
    cin >> g;

    for (int p : primes)
        if (g % p == 0) {
            int exponent = 0;

            while (g % p == 0) {
                g /= p;

                if (has_prime[p])
                    X_max /= p;

                exponent++;
            }

            if (has_prime[p]) {
                needs_query.erase(p);
                X_primes[p] = exponent;
            } else {
                has_prime[p] = true;
                needs_query.insert(p);
            }
        }

    dbg(needs_query);
    do_needed_queries();
}

int solve_range(int low, int high) {
    int answer = max(low + 7, 2 * low);

    if (high - answer <= 7 || high <= 2 * answer)
        return answer;

    return -1;
}

void run_case() {
    has_prime.assign(SIEVE, false);
    needs_query = {};
    X_primes = {};
    queries = 0;
    X_max = X_LIMIT;
    int64_t product = 1;
    int min_prime = 0;

    for (int p : primes) {
        min_prime = p;

        if (exceeds_limit(product, p)) {
            query(product);
            product = 1;

            if (queries >= QUERIES || (!needs_query.empty() && queries >= QUERIES - 1))
                break;
        }

        product *= p;
    }

    do_needed_queries(false);
    int max_remaining = 0;

    while (X_max >= min_prime) {
        X_max /= min_prime;
        max_remaining++;
    }

    int divisors = 1;

    for (auto &pr : X_primes)
        divisors *= pr.second + 1;

    int low = divisors, high = divisors << max_remaining;
    int solution = solve_range(low, high);
    assert(solution >= 0);
    cout << "! " << solution << endl;
}

int main() {
    ios::sync_with_stdio(false);

    sieve(SIEVE);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}