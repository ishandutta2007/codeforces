#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, K;
vector<int> A;

void solve_case() {
    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    int best = INF;
    int answer = -1;

    for (int i = 0; i + K < N; i++) {
        int cost = (A[i + K] - A[i] + 1) / 2;

        if (cost < best) {
            best = cost;
            answer = (A[i] + A[i + K]) / 2;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}