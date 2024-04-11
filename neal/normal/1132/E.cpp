#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
const long long LCM = 840;

long long W;
long long items[N + 1];

int main() {
    cin >> W;
    long long sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> items[i];
        sum += i * items[i];
    }

    if (sum <= W) {
        cout << sum << '\n';
        return 0;
    }

    bitset<N * LCM> possible, next_possible;
    possible[0] = 1;

    for (int i = 1; i <= N; i++) {
        long long jump = i * (items[i] + 1);

        for (int start = 0; start < i; start++) {
            int count = 0;

            for (int k = start; k < N * LCM; k += i) {
                if (k - jump >= 0)
                    count -= possible[k - jump];

                count += possible[k];
                next_possible[k] = count;
            }
        }

        possible = next_possible;
    }

    long long best = 0;

    if (W < N * LCM) {
        for (long long x = 0; x <= W; x++)
            if (possible[x])
                best = max(best, x);
    } else {
        for (int x = 0; x < N * LCM; x++)
            if (possible[x]) {
                if (sum - x <= W) {
                    best = max(best, sum - x);
                    continue;
                }

                long long mod = (sum - x) % LCM;
                long long result = W - (W % LCM - mod + LCM) % LCM;
                best = max(best, result);
            }
    }

    cout << best << '\n';
}