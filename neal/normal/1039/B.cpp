#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
long long N, K;

bool query(long long L, long long R) {
    cout << L << ' ' << R << endl;
    string answer;
    cin >> answer;

    if (answer == "Bad")
        exit(0);

    if (L == R && answer == "Yes")
        exit(0);

    return answer == "Yes";
}

int main() {
    cin >> N >> K;
    long long low = 1, high = N;

    while (true) {
        bool go_for_it = high - low <= 6 * K;

        if (go_for_it) {
            long long location = uniform_int_distribution<long long>(low, high)(rng);
            query(location, location);
        } else {
            long long mid = (low + high) / 2;

            if (query(low, mid))
                high = mid;
            else
                low = mid + 1;
        }

        low = max(low - K, 1LL);
        high = min(high + K, N);
    }
}