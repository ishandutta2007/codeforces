#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int N;
long long M;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    sort(A.rbegin(), A.rend());

    if (accumulate(A.begin(), A.end(), 0LL) < M) {
        cout << -1 << '\n';
        return 0;
    }

    int low = 1, high = N;

    while (low < high) {
        int mid = (low + high) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++)
            sum += max(A[i] - i / mid, 0);

        if (sum >= M)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}