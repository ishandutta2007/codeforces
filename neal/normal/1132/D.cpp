#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long X_MAX = (long long) 2e12 + 5;

int N, K;
vector<long long> A, B;

bool possible(long long X) {
    vector<long long> charge = A;
    vector<vector<int>> needs_charge(K + 1, vector<int>());

    for (int i = 0; i < N; i++) {
        int problem = min(charge[i] / B[i] + 1, (long long) K);
        needs_charge[problem].push_back(i);
    }

    int charges = 0;

    for (int k = 0; k < K; k++) {
        while (!needs_charge[k].empty()) {
            if ((int) needs_charge[k].size() > charges)
                return false;

            int index = needs_charge[k].back();
            needs_charge[k].pop_back();
            charge[index] += X;
            int problem = min(charge[index] / B[index] + 1, (long long) K);
            needs_charge[problem].push_back(index);
            charges--;
        }

        charges++;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    long long low = 0, high = X_MAX;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << (low < X_MAX ? low : -1) << '\n';
}