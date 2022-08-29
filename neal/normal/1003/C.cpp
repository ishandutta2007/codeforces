#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_TEMP = 5005;
const int BINARY_SEARCH_ITERATIONS = 60;

int N, K;
vector<int> temps;

bool possible_avg(double avg) {
    vector<double> prefix_sums(N + 1, 0);
    double min_sum = 0;

    for (int i = 1; i <= N; i++) {
        prefix_sums[i] = prefix_sums[i - 1] + (temps[i - 1] - avg);

        if (i >= K) {
            min_sum = min(min_sum, prefix_sums[i - K]);

            if (prefix_sums[i] >= min_sum)
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    temps.resize(N);

    for (int i = 0; i < N; i++)
        cin >> temps[i];

    double low = 0, high = MAX_TEMP;

    for (int iter = 0; iter < BINARY_SEARCH_ITERATIONS; iter++) {
        double mid = (low + high) / 2;

        if (possible_avg(mid))
            low = mid;
        else
            high = mid;
    }

    cout << setprecision(12) << low << '\n';
    return 0;
}