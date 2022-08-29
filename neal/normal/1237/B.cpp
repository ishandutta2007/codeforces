#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    for (auto &b : B) {
        cin >> b;
        b--;
    }

    vector<int> exit_time(N, -1);

    for (int i = 0; i < N; i++)
        exit_time[B[i]] = i;

    int latest_exit = -1, fined = 0;

    for (int i = 0; i < N; i++) {
        if (exit_time[A[i]] < latest_exit)
            fined++;

        latest_exit = max(latest_exit, exit_time[A[i]]);
    }

    cout << fined << '\n';
}