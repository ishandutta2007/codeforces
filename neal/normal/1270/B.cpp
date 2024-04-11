#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    long long minimum_value = LL_INF;
    int min_start = -1;

    for (int i = 0; i < N; i++) {
        long long current = A[i] - i;

        if (current > minimum_value) {
            cout << "YES" << '\n';
            cout << min_start + 1 << ' ' << i + 1 << '\n';
            return;
        }

        if (current < minimum_value) {
            minimum_value = current;
            min_start = i;
        }
    }

    long long maximum_value = -LL_INF;
    int max_start = -1;

    for (int i = 0; i < N; i++) {
        long long current = A[i] + i;

        if (current < maximum_value) {
            cout << "YES" << '\n';
            cout << max_start + 1 << ' ' << i + 1 << '\n';
            return;
        }

        if (current > maximum_value) {
            maximum_value = current;
            max_start = i;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}