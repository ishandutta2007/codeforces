#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int BINARY_SEARCH_ITER = 100;

int N, M;
vector<int> A, B;

bool works(double fuel) {
    double weight = M + fuel;

    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;
        weight -= weight / A[i];
        weight -= weight / B[next];
    }

    return weight >= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    double low = 0, high = INF;

    for (int iter = 0; iter < BINARY_SEARCH_ITER; iter++) {
        double mid = (low + high) / 2;

        if (works(mid))
            high = mid;
        else
            low = mid;
    }

    if (low > INF - 1)
        cout << -1 << '\n';
    else
        cout << setprecision(12) << low << '\n';

    return 0;
}