#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }

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

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p])
            smallest_factor[p] = p;
}

const int MAX = 3e5 + 5;

int N;
vector<int> A;
vector<vector<int>> factor_lists;
vector<int> multiple_counts;
vector<bool> exists;
vector<bool> has_mask;

bool common(const vector<int> &a, const vector<int> &b) {
    for (int x : a)
        for (int y : b)
            if (x == y)
                return true;

    return false;
}

int get_number(const vector<int> &factors) {
    int product = 1;

    for (int p : factors)
        product *= p;

    return product;
}

int get_mask(const vector<int> &factors, const vector<int> &base_list) {
    int B = base_list.size();
    int mask = (1 << B) - 1;

    for (int i = 0; i < B; i++) {
        bool found = false;

        for (int f : factors)
            if (f == base_list[i]) {
                found = true;
                break;
            }

        if (found)
            mask ^= 1 << i;
    }

    return mask;
}

void minimize(int &a, int b) {
    if (b < a)
        a = b;
}

int main() {
    sieve(MAX);
    scanf("%d", &N);
    A.resize(N);
    int G = 0;

    for (int &a : A) {
        scanf("%d", &a);
        G = __gcd(G, a);
    }

    if (G != 1) {
        puts("-1");
        return 0;
    }

    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    N = A.size();

    for (int i = 0; i < N; i++)
        if (A[i] == 1) {
            puts("1");
            return 0;
        }

    for (int i = 0; i < N; i++) {
        vector<int> factorization;

        while (A[i] != 1) {
            int p = smallest_factor[A[i]];
            factorization.push_back(p);

            do {
                A[i] /= p;
            } while (A[i] % p == 0);
        }

        if (factorization.size() == 1) {
            puts("2");
            return 0;
        }

        factor_lists.push_back(factorization);
    }

    sort(factor_lists.begin(), factor_lists.end());
    factor_lists.resize(unique(factor_lists.begin(), factor_lists.end()) - factor_lists.begin());
    N = factor_lists.size();
    exists.assign(MAX, false);

    for (auto &factors : factor_lists) {
        int number = get_number(factors);
        assert(!exists[number]);
        exists[number] = true;
    }

    vector<vector<int>> new_factor_lists;

    for (auto &factors : factor_lists) {
        int f = factors.size();
        bool skip = false;

        for (int mask = 0; mask < (1 << f) - 1; mask++) {
            int product = 1;

            for (int i = 0; i < f; i++)
                if (mask & 1 << i)
                    product *= factors[i];

            if (exists[product])
                skip = true;
        }

        if (!skip)
            new_factor_lists.push_back(factors);
    }

    factor_lists = new_factor_lists;
    N = factor_lists.size();
    multiple_counts.assign(MAX, 0);

    for (auto &factors : factor_lists) {
        int f = factors.size();

        for (int mask = 0; mask < 1 << f; mask++) {
            int product = 1;

            for (int i = 0; i < f; i++)
                if (mask & 1 << i)
                    product *= factors[i];

            multiple_counts[product]++;
        }
    }

    for (auto &factors : factor_lists) {
        int f = factors.size();
        int count = 0;

        for (int mask = 0; mask < 1 << f; mask++) {
            int product = 1;

            for (int i = 0; i < f; i++)
                if (mask & 1 << i)
                    product *= factors[i];

            count += (__builtin_popcount(mask) % 2 == 0 ? +1 : -1) * multiple_counts[product];
        }

        // cerr << factors << ": " << count << endl;
        assert(count >= 0);

        if (count > 0) {
            puts("2");
            return 0;
        }
    }

    // N should be smallish at this point, ~10,000
    // cerr << "N is " << N << endl;
    int best = N;

    for (int i = 0; i < N; i++) {
        int F = factor_lists[i].size();
        has_mask.assign(1 << F, false);

        for (int j = 0; j < N; j++)
            has_mask[get_mask(factor_lists[j], factor_lists[i])] = true;

        vector<int> dp(1 << F, MAX);
        dp[0] = 0;

        for (int mask = 0; mask < 1 << F; mask++)
            for (int add = 1; add < 1 << F; add++)
                if (has_mask[add])
                    minimize(dp[mask | add], dp[mask] + 1);

        minimize(best, dp[(1 << F) - 1] + 1);
    }

    printf("%d\n", best);
}