#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<int> B(N);

    for (int i = 0; i < N; i++)
        cin >> B[i];

    vector<int> gaps;

    for (int i = 0; i + 1 < N; i++)
        gaps.push_back(B[i + 1] - B[i] - 1);

    int total = B.back() - B.front() + 1;
    sort(gaps.rbegin(), gaps.rend());

    for (int k = 1; k < K; k++)
        total -= gaps[k - 1];

    cout << total << '\n';
}