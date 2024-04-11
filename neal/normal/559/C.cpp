#include <cstdio>
#include <algorithm>
using namespace std;

const int HW_MAX = 200005, N_MAX = 2005, MOD = 1000000007;

int H, W, N;
long long factorial[HW_MAX];
pair<int, int> cells[N_MAX];
long long paths[N_MAX];

long long fast_power(long long a, long long power) {
    long long p = 1;

    while (power > 0) {
        if (power & 1) {
            p = p * a % MOD;
        }

        a = a * a % MOD;
        power >>= 1;
    }

    return p;
}

long long inverse(long long a) {
    return fast_power(a, MOD - 2);
}

long long num_paths(long long height, long long width) {
    return factorial[height + width] * inverse(factorial[height] * factorial[width] % MOD) % MOD;
}

int main() {
    factorial[0] = 1;

    for (int i = 1; i < HW_MAX; i++) {
        factorial[i] = i * factorial[i - 1] % MOD;
    }

    scanf("%d %d %d", &H, &W, &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cells[i].first, &cells[i].second);
        cells[i].first--;
        cells[i].second--;
    }

    sort(cells, cells + N);
    cells[N] = make_pair(H - 1, W - 1);

    for (int i = 0; i <= N; i++) {
        paths[i] = num_paths(cells[i].first, cells[i].second);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (cells[i].second <= cells[j].second) {
                int height = cells[j].first - cells[i].first;
                int width = cells[j].second - cells[i].second;
                paths[j] -= paths[i] * num_paths(height, width) % MOD;
                paths[j] = (paths[j] + MOD) % MOD;
            }
        }
    }

    printf("%d\n", (int) paths[N]);
    return 0;
}