#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    int answer = INF, best = -1;

    for (int t = 1; t <= 100; t++) {
        int cost = 0;

        for (int i = 0; i < N; i++)
            cost += min(abs(A[i] - t), min(abs(A[i] - (t - 1)), abs(A[i] - (t + 1))));

        if (cost < answer) {
            answer = cost;
            best = t;
        }
    }

    cout << best << ' ' << answer << '\n';
}