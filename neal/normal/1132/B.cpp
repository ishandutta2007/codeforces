#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.rbegin(), A.rend());
    cin >> M;

    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        cout << sum - A[q - 1] << '\n';
    }
}