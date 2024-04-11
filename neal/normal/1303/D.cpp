#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int BITS = 60;

long long N;
int M;
vector<long long> freq;

void run_case() {
    cin >> N >> M;
    freq.assign(BITS, 0);
    long long A_sum = 0;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        freq[__builtin_ctz(a)]++;
        A_sum += a;
    }

    if (A_sum < N) {
        cout << -1 << '\n';
        return;
    }

    long long sum = 0, answer = 0;

    for (int b = 0; b < BITS; b++) {
        sum += freq[b] << b;
        freq[b] = 0;

        if (N >> b & 1) {
            if (sum >= 1LL << b) {
                sum -= 1LL << b;
            } else {
                for (int higher = b + 1; higher < BITS; higher++)
                    if (freq[higher] > 0) {
                        freq[higher]--;

                        for (int i = b; i < higher; i++)
                            freq[i]++;

                        answer += higher - b;
                        break;
                    }

                assert(freq[b] > 0);
                sum += freq[b] << b;
                freq[b] = 0;
            }
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}