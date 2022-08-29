#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long solve(long long N, long long R, long long r_status, long long K) {
    // TODO: include r_status in count
    long long best = -1;

    if ((double) N * N < K) {
        // Loop over before + after
        for (long long before_and_after = 0; before_and_after <= N - 1; before_and_after++) {
            long long t_mult = N + before_and_after + r_status;
            long long fixed = R + 1 + r_status;
            long long remaining = K - fixed;

            // t_mult * t + before = remaining
            // before <= before_and_after; before <= R; after <= N - 1 - R

            long long t = remaining / t_mult;
            long long before = remaining - t_mult * t;

            if (before_and_after - before > N - 1 - R) {
                long long subtract = (before_and_after - before - (N - 1 - R) + t_mult - 1) / t_mult;
                t -= subtract;
                before += t_mult * t;
            }

            if (t >= 0 && before >= 0 && before_and_after - before <= N - 1 - R && before <= before_and_after && before <= R)
                best = max(best, before_and_after + r_status);
        }
    } else {
        // Loop over T
        for (long long t = 0; ; t++) {
            long long remaining = K - (N * t + R + 1 + r_status * (t + 1));

            if (remaining < 0)
                break;

            if (t == 0) {
                long long before = remaining;
                long long after = N - 1 - R;

                if (before >= 0 && before <= R && after >= 0 && after <= N - 1 - R) {
                    best = max(best, before + after + r_status);
                    continue;
                }
            }

            // remaining = before * (t + 1) + after * t
            // before <= R; after <= N - 1 - R

            if (R * (t + 1) + (N - 1 - R) * t < remaining)
                continue;

            long long need = remaining / t;
            long long extra = remaining % t;

            long long before = extra;
            long long after = need - extra;

            if (before >= 0 && before <= R && after >= 0 && after <= N - 1 - R) {
                best = max(best, before + after + r_status);
                continue;
            }

            long long too_much = after - (N - 1 - R);
            long long move_over = (too_much + t) / (t + 1);

            before += move_over * t;
            after -= move_over * (t + 1);

            if (before >= 0 && before <= R && after >= 0 && after <= N - 1 - R)
                best = max(best, before + after + r_status);
        }
    }

    return best;
}

int main() {
    long long N, K, L, R;
    cin >> N >> L >> R >> K;
    R = (R - L + N) % N;
    long long most = -1;

    for (long long r_status = 0; r_status <= 1; r_status++)
        for (long long k = K; k <= K + r_status; k++)
            most = max(most, solve(N, R, r_status, k));

    cout << most << '\n';
}