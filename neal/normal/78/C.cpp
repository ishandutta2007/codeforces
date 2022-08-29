#include <algorithm>
#include <array>
#include <cassert>
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

// Prime factorizes n in worst case O(sqrt n).
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    assert(n >= 1);
    vector<pair<int64_t, int>> result;

    for (int64_t p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

// http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;

int64_t factors[FACTORS_MAX];

int generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    static int64_t buffer[FACTORS_MAX];
    int f_size = 0;
    factors[f_size++] = 1;

    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
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


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    auto prime_factors = prime_factorize(M);
    int F = generate_factors(prime_factors, true);

    vector<int> seen(F + 1, -1);
    int seen_index = 0;

    vector<int> SG(F, 0);

    for (int i = 0; i < F; i++) {
        int number = factors[i];

        if (number < K)
            continue;

        seen_index++;

        for (int j = 0; j < i; j++)
            if (factors[j] >= K && number % factors[j] == 0) {
                int parity = (number / factors[j]) % 2;

                if (parity % 2 == 0)
                    seen[0] = seen_index;
                else
                    seen[SG[j]] = seen_index;
            }

        SG[i] = 0;

        while (seen[SG[i]] == seen_index)
            SG[i]++;
    }

    cout << (N % 2 == 0 || SG[F - 1] == 0 ? "Marsel" : "Timur") << '\n';
}