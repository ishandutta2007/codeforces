#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

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

int K;

int solve(vector<int> numbers) {
    int N = numbers.size();

    if (*max_element(numbers.begin(), numbers.end()) < 0)
        return mod_mul(K, mod_pow(K - 1, N - 1));

    int start = 0, end = N - 1;
    int answer = 1, count = 1;

    while (numbers[start] < 0) {
        count = mod_mul(count, K - 1);
        start++;
    }

    answer = mod_mul(answer, count);
    count = 1;

    while (numbers[end] < 0) {
        count = mod_mul(count, K - 1);
        end--;
    }

    answer = mod_mul(answer, count);
    assert(numbers[start] >= 0 && numbers[end] >= 0);
    int prev = start;

    for (int i = start + 1; i <= end; i++)
        if (numbers[i] >= 0) {
            count = 1;

            if ((i - prev) % 2 == 0) {
                for (int j = prev + 1; j < i; j++)
                    count = mod_mul(count, K - 1);

                int normal = mod_mul(mod_add(count, 1), mod_inv(K));
                count = mod_sub(count, normal);

                if (numbers[prev] == numbers[i])
                    count = mod_add(count, 1);
            } else {
                for (int j = prev + 1; j < i; j++)
                    count = mod_mul(count, K - 1);

                int normal = mod_mul(mod_sub(count, 1), mod_inv(K));
                count = mod_sub(count, normal);

                if (numbers[prev] == numbers[i])
                    count = mod_sub(count, 1);
            }

            answer = mod_mul(answer, count);
            prev = i;
        }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N >> K;
    vector<int> even, odd;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (i % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }

    cout << mod_mul(solve(even), solve(odd)) << '\n';
}