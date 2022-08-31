#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int T_MAX = 10005;
const int SIEVE_MAX = 32000000;
const int SMALL_MAX = 100005;
const long long LL_INF = 2e18;

struct video {
    long long n, k;
    int index;

    bool operator<(const video &other) const {
        return make_pair(k, n) < make_pair(other.k, other.n);
    }
};

int T;
video videos[T_MAX];

vector<bool> is_prime(SIEVE_MAX, true);
vector<int> primes;
vector<bool> answers(T_MAX, false);

long long smallest_sum[SMALL_MAX];

void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < SIEVE_MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < SIEVE_MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i < SIEVE_MAX; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
}

int mod_pow(long long a, int p, int mod) {
    long long result = 1;

    while (p > 0) {
        if (p & 1)
            result = result * a % mod;

        a = a * a % mod;
        p >>= 1;
    }

    return result;
}

int mod_inv(int a, int mod) {
    return mod_pow(a, mod - 2, mod);
}

priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

void check_and_add(int value, long long sum) {
    if (sum < smallest_sum[value]) {
        smallest_sum[value] = sum;
        pq.push(make_pair(sum, value));
    }
}

void dijkstra(vector<long long> k_primes) {
    int small_prime = (int) k_primes[0];
    assert(small_prime < SMALL_MAX);

    for (int i = 0; i < small_prime; i++) {
        smallest_sum[i] = LL_INF;
    }

    assert(pq.empty());
    check_and_add(0, 0);

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        int value = top.second;
        long long sum = top.first;

        // if (sum > smallest_sum[value])
        //     continue;

        for (long long p : k_primes) {
            int next_value = (value + p) % small_prime;
            long long next_sum = sum + p;
            check_and_add(next_value, next_sum);
        }
    }

    smallest_sum[0] = small_prime;
}

void solve(int start, int end) {
    long long k = videos[start].k;
    vector<long long> k_primes;

    for (int p : primes) {
        if (p > k)
            break;

        if (k % p == 0) {
            k_primes.push_back(p);

            do {
                k /= p;
            } while (k % p == 0);
        }
    }

    if (k > 1) {
        k_primes.push_back(k);
    }

    sort(k_primes.begin(), k_primes.end());

    for (int i = start; i < end; i++) {
        long long n = videos[i].n;
        bool answer;

        if (k_primes.empty()) {
            answer = false;
        } else if (k_primes.size() == 1) {
            answer = n % k_primes[0] == 0;
        } else if (k_primes.size() == 2) {
            long long a = k_primes[0], b = k_primes[1];
            long long goal = n % a;
            long long smallest = (goal * mod_inv(b, a) % a) * b;
            answer = n >= smallest;
        } else {
            int small_prime = (int) k_primes[0];

            if (i == start) {
                dijkstra(k_primes);
            }

            answer = n >= smallest_sum[n % small_prime];
        }

        answers[videos[i].index] = answer;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> videos[i].n >> videos[i].k;
        videos[i].index = i;
    }

    sort(videos, videos + T);

    for (int i = 0, j = 0; i < T; i = j) {
        while (j < T && videos[j].k == videos[i].k)
            j++;

        solve(i, j);
    }

    for (int i = 0; i < T; i++) {
        cout << (answers[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}