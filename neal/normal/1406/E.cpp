#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

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


int N;

int query(char type, int a) {
    if (a > N)
        return 0;

    cout << type << ' ' << a << endl;

    if (type == 'C')
        exit(0);

    int result;
    cin >> result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;

    if (N == 1)
        query('C', 1);

    sieve(N);
    vector<int> big;
    int answer = 1;

    for (int p : primes)
        if (int64_t(p) * p <= N) {
            query('B', p);
            int pp = p;

            while (query('A', pp) > 0) {
                answer *= p;
                pp *= p;
            }
        } else {
            big.push_back(p);
        }

    int check_every = int(sqrt(big.size())) + 1;
    int start_count = query('A', 1);
    vector<int> queued;

    auto &&check = [&](bool forced = false) {
        int current_count = query('A', 1);

        if (forced || current_count != start_count - int(queued.size())) {
            for (int x : queued)
                if (query('A', x) > 0)
                    query('C', answer * x);

            assert(false);
        } else {
            start_count = current_count;
            queued.clear();
        }
    };

    for (int p : big) {
        int before_remove = query('B', p);
        assert(before_remove >= 1);
        queued.push_back(p);

        if (before_remove > 1)
            check(true);
        else if (int(queued.size()) >= check_every)
            check();
    }

    check();
    query('C', answer);
}