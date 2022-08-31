#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
long long P;
vector<long long> A;

bool possible(int buy) {
    if (buy > N)
        return false;

    if (buy % K == 0) {
        long long sum = 0;

        for (int i = 1; i <= buy / K; i++)
            sum += A[i * K - 1];

        return sum <= P;
    }

    int round_up = buy + (K - buy % K) % K;

    if (possible(round_up))
        return true;

    long long sum = 0;

    for (int i = 0; i < buy % K; i++)
        sum += A[i];

    for (int i = 1; i <= buy / K; i++)
        sum += A[i * K + buy % K - 1];

    return sum <= P;
}

void run_case() {
    cin >> N >> P >> K;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int low = 0, high = N;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}