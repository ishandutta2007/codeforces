#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, A, B, L;
long long X, Y, K;
vector<long long> P;

void solve_case() {
    cin >> N;
    P.resize(N);

    for (auto &p : P) {
        cin >> p;
        p /= 100;
    }

    cin >> X >> A >> Y >> B >> K;
    sort(P.rbegin(), P.rend());
    int low = 0, high = N + 1;

    while (low < high) {
        int mid = (low + high) / 2;
        vector<long long> percents(N, 0);

        for (int i = 0; i < mid; i++) {
            if ((i + 1) % A == 0)
                percents[i] += X;

            if ((i + 1) % B == 0)
                percents[i] += Y;
        }

        sort(percents.rbegin(), percents.rend());
        long long sum = 0;

        for (int i = 0; i < mid; i++)
            sum += percents[i] * P[i];

        if (sum >= K)
            high = mid;
        else
            low = mid + 1;
    }

    cout << (low <= N ? low : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}