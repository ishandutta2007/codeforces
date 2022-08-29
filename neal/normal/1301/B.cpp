#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
vector<long long> A;

pair<bool, long long> possible(long long m) {
    long long k_low = -LL_INF, k_high = LL_INF;
    long long low = -LL_INF, high = LL_INF;

    for (long long &a : A) {
        low -= m;
        high += m;

        if (a >= 0) {
            if (a < low || a > high)
                return {false, -1};

            low = high = a;
        } else {
            k_low = max(k_low, low);
            k_high = min(k_high, high);
        }
    }

    reverse(A.begin(), A.end());
    low = -LL_INF, high = LL_INF;

    for (long long &a : A) {
        low -= m;
        high += m;

        if (a >= 0) {
            if (a < low || a > high)
                return {false, -1};

            low = high = a;
        } else {
            k_low = max(k_low, low);
            k_high = min(k_high, high);
        }
    }

    return {k_low <= k_high, max(k_low, 0LL)};
}

void run_case() {
    cin >> N;
    A.resize(N);

    for (long long &a : A)
        cin >> a;

    long long low = 0, high = 2e9;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (possible(mid).first)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << ' ' << possible(low).second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}