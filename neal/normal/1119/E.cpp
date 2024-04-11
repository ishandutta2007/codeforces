#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    long long total = 0, extra = 0;

    for (int i = 0; i < N; i++) {
        long long pairs = min(A[i] / 2LL, extra);
        total += pairs;
        A[i] -= 2 * pairs;
        extra -= pairs;

        total += A[i] / 3;
        A[i] %= 3;
        extra += A[i];
    }

    cout << total << '\n';
}