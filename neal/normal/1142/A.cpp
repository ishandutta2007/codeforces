#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

long long N, K, NK;
long long A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    cin >> A >> B;
    NK = N * K;

    vector<long long> As, Bs;

    for (long long i = 0; i < K; i++) {
        if (min(i, K - i) == A)
            As.push_back(i);

        if (min(i, K - i) == B)
            Bs.push_back(i);
    }

    long long low = LL_INF, high = -LL_INF;

    for (long long a : As)
        for (long long b : Bs)
            for (long long jump = 0; jump < N; jump++) {
                long long x = a, y = b + jump * K;
                long long distance = ((y - x) % NK + NK) % NK;
                long long steps = NK / __gcd(NK, distance);
                low = min(low, steps);
                high = max(high, steps);
            }

    cout << low << ' ' << high << '\n';
}