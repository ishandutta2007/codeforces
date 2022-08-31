#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Prime factorizes n in worst case O(sqrt n).
vector<pair<long long, int>> prime_factorize(long long n) {
    assert(n >= 1);
    vector<pair<long long, int>> result;

    for (long long p = 2; p * p <= n; p++)
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

const long long LL_INF = (long long) 2e18 + 5;

int N;
long long S;
vector<long long> A;

long long solve(long long k) {
    assert(S % k == 0);
    vector<long long> A_copy = A;
    vector<long long> B(N, 0);

    for (auto &a : A)
        a %= k;

    long long total = 0;

    for (int i = 0, j = 0; i < N - 1; i = j) {
        long long sum = 0;
        long long cost = 0;
        long long cheapest = LL_INF;

        while (j < N && sum < k) {
            B[j] = min(A[j], k - sum);
            A[j] -= B[j];
            cost += B[j] * (j - i);
            sum += B[j];
            j++;
        }

        if (sum == 0)
            break;

        assert(sum == k);
        j--;
        long long running_sum = 0;

        for (int t = i; t <= j; t++) {
            cheapest = min(cheapest, cost);
            running_sum += B[t];
            cost += running_sum;
            cost -= k - running_sum;
        }

        for (int t = i; t <= j; t++)
            B[t] = 0;

        total += cheapest;
    }

    A = A_copy;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    S = 0;

    for (auto &a : A) {
        cin >> a;
        S += a;
    }

    if (S <= 1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<long long, int>> primes = prime_factorize(S);
    long long best = LL_INF;

    for (auto &pf : primes)
        best = min(best, solve(pf.first));

    cout << best << '\n';
}