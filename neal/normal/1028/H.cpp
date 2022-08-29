#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_PRIME_FACTORS = 7;
const int MAX_ANSWER = 2 * MAX_PRIME_FACTORS + 1;
const int N_MAX = 194598 + 5;
const int A_MAX = 5032107 + 5;

int N, Q;
int latest_index[N_MAX][MAX_ANSWER];
int latest_index_at_number[A_MAX][MAX_ANSWER];

template<typename T>
void maximize(T &a, const T &b) {
    if (b > a)
        a = b;
}

int main() {
    scanf("%d %d", &N, &Q);

    for (int index = 1; index <= N; index++) {
        int element;
        scanf("%d", &element);
        vector<int> primes;

        for (int p = 2; p * p <= element; p++)
            if (element % p == 0) {
                while (element % (p * p) == 0)
                    element /= p * p;

                if (element % p == 0) {
                    element /= p;
                    primes.push_back(p);
                }
            }

        if (element > 1)
            primes.push_back(element);

        int ps = primes.size();
        assert(ps <= MAX_PRIME_FACTORS);

        for (int i = 0; i < MAX_ANSWER; i++)
            latest_index[index][i] = latest_index[index - 1][i];

        for (int mask = 0; mask < 1 << ps; mask++) {
            int cost = __builtin_popcount(mask);
            int product = 1;

            for (int i = 0; i < ps; i++)
                if ((mask & 1 << i) == 0)
                    product *= primes[i];

            for (int c = 0; c <= MAX_PRIME_FACTORS; c++)
                maximize(latest_index[index][cost + c], latest_index_at_number[product][c]);

            maximize(latest_index_at_number[product][cost], index);
        }
    }

    for (int q = 0; q < Q; q++) {
        int L, R;
        scanf("%d %d", &L, &R);
        bool found = false;

        for (int cost = 0; cost < MAX_ANSWER; cost++)
            if (latest_index[R][cost] >= L) {
                printf("%d\n", cost);
                found = true;
                break;
            }

        assert(found);
    }

    return 0;
}