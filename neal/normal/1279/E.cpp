#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 55;
const long long LL_INF = (long long) 2e18 + 5;

long long limited_add(long long a, long long b) {
    return min(a + b, LL_INF);
}

long long limited_mul(long long a, long long b) {
    return (double) a * b > LL_INF ? LL_INF : a * b;
}

long long factorial[N_MAX];
long long how_many_good[N_MAX];

void prepare() {
    factorial[0] = 1;

    for (int i = 1; i < N_MAX; i++)
        factorial[i] = limited_mul(i, factorial[i - 1]);

    how_many_good[0] = 1;

    for (int n = 1; n < N_MAX; n++) {
        how_many_good[n] = 0;

        for (int k = 1; k <= n; k++)
            how_many_good[n] = limited_add(how_many_good[n], limited_mul(factorial[max(k - 2, 0)], how_many_good[n - k]));
    }
}

int N;

// Count how many good permutations start with this prefix.
long long count_starting_with(vector<int> prefix) {
    vector<bool> has_in(N, false);

    for (int p : prefix)
        if (p >= 0)
            has_in[p] = true;

    vector<bool> visited(N, false);
    int start = 0;

    while (true) {
        if (start >= N || prefix[start] < 0)
            return how_many_good[N - start];

        int last = prefix[start];

        if (last < start)
            return 0;

        if (prefix[last] >= 0) {
            // Need to verify that the cycle here is valid.
            int current = start;
            int length = 0;

            while (!visited[current]) {
                visited[current] = true;
                length++;

                if (prefix[current] < start || prefix[current] > last)
                    return 0;

                current = prefix[current];
            }

            if (length != last - start + 1)
                return 0;

            start = last + 1;
            continue;
        }

        // This is the last cycle.
        // Number of ways = (number of paths excluding start)!
        int paths = 0;

        for (int i = start; i <= last; i++)
            if (!has_in[i]) {
                int current = i;

                while (!visited[current] && prefix[current] >= 0) {
                    if (prefix[current] < start || prefix[current] > last)
                        return 0;

                    visited[current] = true;
                    current = prefix[current];
                }

                // Check for a cycle.
                if (current == i && prefix[current] >= 0)
                    return 0;

                if (prefix[current] < 0)
                    paths++;
            }

        for (int i = start + 1; i < last; i++) {
            if (prefix[i] >= 0 && (prefix[i] < start || prefix[i] > last))
                return 0;

            // Check for a cycle.
            if (prefix[i] >= 0 && !visited[i])
                return 0;
        }

        int next = last + 1;
        return limited_mul(factorial[paths - 1], how_many_good[N - next]);
    }
}

void test() {
    N = 4;
    vector<int> permutation = {3, 0, -1, -1};
    // cerr << count_starting_with(permutation) << endl;
}

long long K;

void run_case() {
    cin >> N >> K;
    K--;

    if (K >= how_many_good[N]) {
        cout << -1 << '\n';
        return;
    }

    vector<int> permutation(N, -1);

    for (int position = 0; position < N; position++) {
        vector<bool> seen(N, false);

        for (int i = 0; i < position; i++)
            seen[permutation[i]] = true;

        for (int here = 0; here < N; here++) {
            if (seen[here])
                continue;

            permutation[position] = here;
            long long count = count_starting_with(permutation);

            if (K < count)
                break;

            K -= count;
        }
    }

    for (int i = 0; i < N; i++)
        cout << permutation[i] + 1 << (i < N - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prepare();
    test();

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}