#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    vector<long long> sums;
    long long sum = 0;

    for (int i = N - 1; i >= 0; i--) {
        sum += A[i];

        if (i > 0)
            sums.push_back(sum);
    }

    long long answer = sum;
    nth_element(sums.begin(), sums.begin() + K - 1, sums.end(), greater<long long>());

    for (int k = 0; k < K - 1; k++)
        answer += sums[k];

    cout << answer << '\n';
}