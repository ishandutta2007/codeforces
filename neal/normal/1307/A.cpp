#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, D;
vector<int> A;

void run_case() {
    cin >> N >> D;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    for (int i = 1; i < N; i++) {
        int take = min(D, A[i] * i);
        take -= take % i;
        int move = take / i;
        A[0] += move;
        D -= take;
    }

    cout << A[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}