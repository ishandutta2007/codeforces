#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);

    for (long long &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int mid = N / 2;
    long long current = A[mid];

    for (int i = mid + 1; i <= N; i++) {
        long long gap = i == N ? LL_INF : A[i] - current;
        long long add = min(K / (i - mid), gap);
        current += add;
        K -= add * (i - mid);
    }

    cout << current << '\n';
}