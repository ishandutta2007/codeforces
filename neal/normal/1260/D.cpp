#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct trap {
    int L, R, D;

    bool operator<(const trap &other) const {
        return D < other.D;
    }
};

bool compare_L(const trap &x, const trap &y) {
    return x.L < y.L;
}

int M, N, K, T;
vector<int> A;
vector<trap> traps;

bool possible(int soldiers) {
    vector<trap> current_traps;

    for (trap &tr : traps)
        if (tr.D > A[soldiers - 1])
            current_traps.push_back(tr);

    sort(current_traps.begin(), current_traps.end(), compare_L);
    int end = 0, sum = 0;

    for (trap &tr : current_traps) {
        if (tr.L > end)
            end = tr.L;

        if (tr.R > end) {
            sum += tr.R - end;
            end = tr.R;
        }
    }

    return N + 2 * sum <= T;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K >> T;
    N++;
    A.resize(M);
    traps.resize(K);

    for (auto &a : A)
        cin >> a;

    for (trap &tr : traps) {
        cin >> tr.L >> tr.R >> tr.D;
        tr.L--;
    }

    sort(A.rbegin(), A.rend());
    sort(traps.rbegin(), traps.rend());
    int low = 0, high = M;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
}