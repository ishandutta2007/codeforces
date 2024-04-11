#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

const long long LL_INF = (long long) 2e18 + 5;

int P;
long long N, K;
vector<long long> A, E;
map<vector<long long>, vector<pair<long long, int>>> options;

int main() {
    scanf("%lld %lld", &N, &K);
    A.resize(N);
    E.resize(N);

    for (long long &a : A)
        scanf("%lld", &a);

    for (long long &e : E)
        scanf("%lld", &e);

    long long G = 0;

    for (long long a : A)
        G = __gcd(G, a);

    if (G == 1) {
        puts("0");
        return 0;
    }

    vector<long long> primes;
    long long F = G;

    for (long long p = 2; p * p <= F; p++)
        if (F % p == 0) {
            do {
                F /= p;
            } while (F % p == 0);

            primes.push_back(p);
        }

    if (F > 1) {
        primes.push_back(F);
        F = 1;
    }

    P = primes.size();

    for (int i = 0; i < N; i++) {
        vector<long long> powers(P, 1);
        long long a = A[i];

        for (int p = 0; p < P; p++)
            do {
                a /= primes[p];
                powers[p] *= primes[p];
            } while (a % primes[p] == 0);

        options[powers].emplace_back(E[i], i);
    }

    vector<vector<pair<long long, int>>> best_costs(1 << P);

    for (auto &option : options) {
        const vector<long long> &powers = option.first;
        vector<pair<long long, int>> &costs = option.second;
        sort(costs.begin(), costs.end());

        for (int c = 0; c < min((int) costs.size(), P); c++)
            for (int mask = 0; mask < 1 << P; mask++) {
                long long product = 1;

                for (int i = 0; i < P; i++)
                    if (mask >> i & 1)
                        product *= powers[i];

                if (product <= K)
                    best_costs[mask].push_back(costs[c]);
            }
    }

    vector<vector<int>> masks(N);

    for (int mask = 0; mask < 1 << P; mask++) {
        sort(best_costs[mask].begin(), best_costs[mask].end());

        for (int i = 0; i < min((int) best_costs[mask].size(), P); i++)
            masks[best_costs[mask][i].second].push_back(mask);
    }

    vector<vector<long long>> dp(P + 1, vector<long long>(1 << P, LL_INF));
    dp[0][0] = 0;

    for (int index = 0; index < N; index++)
        if (!masks[index].empty())
            for (int p = P - 1; p >= 0; p--)
                for (int mask : masks[index]) {
                    int opposite = ((1 << P) - 1) ^ mask, sub = opposite;

                    do {
                        minimize(dp[p + 1][mask | sub], dp[p][sub] + E[index]);
                        sub = (sub - 1) & opposite;
                    } while (sub != opposite);
                }

    long long answer = LL_INF;

    for (int c = 0; c <= P; c++)
        if (dp[c][(1 << P) - 1] < LL_INF)
            answer = min(answer, c * dp[c][(1 << P) - 1]);

    printf("%lld\n", answer < LL_INF ? answer : -1);
}