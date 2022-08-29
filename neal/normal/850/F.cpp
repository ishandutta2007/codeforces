#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

inline int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}

inline int mod_sub(int a, int b, int m = MOD) {
    int diff = a - b;
    return diff < 0 ? diff + m : diff;
}

inline int mod_mul(int a, int b, int m = MOD) {
    return (uint64_t) a * b % m;
}

inline int mod_pow(int a, long long p, int m = MOD) {
    assert(p >= 0);
    int result = 1;

    while (p > 0) {
        if (p & 1)
            result = mod_mul(result, a, m);

        a = mod_mul(a, a, m);
        p >>= 1;
    }

    return result;
}

inline int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

int N, M, T;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    M = *max_element(A.begin(), A.end());
    T = accumulate(A.begin(), A.end(), 0);
    vector<int> answer(M + 1, 0);
    answer[1] = mod_mul(mod_mul(T - 1, T - 1), mod_inv(T));

    for (int t = 1; t < M; t++)
        answer[t + 1] = mod_sub(mod_sub(mod_add(answer[t], answer[t]), answer[t - 1]), mod_mul(T - 1, mod_inv(T - t)));

    int total = 0;

    for (int a : A)
        total = mod_add(total, answer[a]);

    cout << total << '\n';
}