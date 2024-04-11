#include <iostream>
using namespace std;

long long K, KK;

// Returns the value of the only sum in the range [x * KK + 1, (x + 1) * KK].
long long get_sum(long long x) {
    if (x == 0)
        return K * (K + 1) / 2;

    // Find the missing number for x / K.
    long long low_sum = get_sum(x / K);
    long long changed_group = (low_sum - 1) % KK / K;
    long long changed_index = (low_sum - 1) % KK % K;

    long long group = x % K;
    long long sum = (x / K) * KK * K + K * (K + 1) / 2 + group * K * K;

    if (group > changed_group)
        sum += K;
    else if (group == changed_group)
        sum += K - changed_index;

    return sum;
}

long long get_index(long long n) {
    long long x = (n - 1) / KK;
    long long sum = get_sum(x);

    if (sum == n)
        return (x + 1) * (K + 1) - 1;

    long long start = x * K * (K + 1);
    long long relative = (n - 1) % KK;

    if (n > sum)
        relative--;

    // Include the sums before n in our bucket.
    relative += relative / K;
    return start + relative;
}

void solve_case() {
    long long N;
    scanf("%lld %lld", &N, &K);

    // There is exactly one sum for every segment [x * KK + 1, (x + 1) * KK].
    KK = K * K + 1;
    printf("%lld\n", get_index(N) + 1);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}