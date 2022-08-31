#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {2};

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

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
        }
}


const int G_MAX = 2e5 + 5;

bitset<G_MAX> is_move;
int SG[G_MAX];
vector<bitset<G_MAX>> can_reach;

void solve(int F) {
    sieve(G_MAX);
    is_move.reset();

    for (int p : primes)
        if (p < G_MAX)
            is_move[p] = 1;

    for (int p : primes)
        for (int q : primes) {
            long long product = (long long) p * q;

            if (product < G_MAX)
                is_move[product] = 1;
            else
                break;
        }

    is_move[F] = 0;
    SG[0] = 0;
    can_reach.resize(1);
    can_reach[0] |= is_move;

    for (int g = 1; g < G_MAX; g++) {
        int s = 0;

        while (s < (int) can_reach.size() && can_reach[s][g])
            s++;

        if (s >= (int) can_reach.size())
            can_reach.emplace_back();

        SG[g] = s;
        can_reach[s] |= is_move << g;
    }
}

int main() {
    int N, F;
    scanf("%d %d", &N, &F);
    solve(F);
    int answer = 0;

    for (int i = 0; i < N; i++) {
        int b, w, r;
        scanf("%d %d %d", &b, &w, &r);
        answer ^= SG[w - b - 1] ^ SG[r - w - 1];
    }

    puts(answer ? "Alice" : "Bob");
    puts(answer ? "Bob" : "Alice");
}