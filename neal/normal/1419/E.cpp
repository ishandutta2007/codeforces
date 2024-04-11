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

// This covers up to 2^64. See http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;

vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    static int64_t buffer[FACTORS_MAX];
    int product = 1;

    for (auto &pf : prime_factors)
        product *= pf.second;

    vector<int64_t> factors = {1};
    factors.reserve(product);

    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());

        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section, factors.begin() + i + section, factors.begin() + i + length, buffer);
                    copy(buffer, buffer + length, factors.begin() + i);
                }
    }

    return factors;
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N;
    cin >> N;
    vector<pair<int64_t, int>> prime_factors = prime_factorize(N);
    vector<int64_t> factors = generate_factors(prime_factors);
    factors.erase(factors.begin());
    int F = int(factors.size());
    vector<bool> used(F, false);

    int P = int(prime_factors.size());
    prime_factors.push_back(prime_factors.front());
    vector<int> which_middle(P, -1);

    for (int i = 0; i < P; i++)
        for (int f = 0; f < F; f++)
            if (!used[f] && factors[f] % prime_factors[i].first == 0 && factors[f] % prime_factors[i + 1].first == 0) {
                which_middle[i] = f;
                used[f] = true;
                break;
            }

    vector<int> order;
    int cost = 0;

    for (int i = 0; i < P; i++) {
        for (int f = 0; f < F; f++)
            if (!used[f] && factors[f] % prime_factors[i].first == 0) {
                order.push_back(factors[f]);
                used[f] = true;
            }

        if (which_middle[i] >= 0)
            order.push_back(factors[which_middle[i]]);
        else
            cost++;
    }

    output_vector(order);
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}