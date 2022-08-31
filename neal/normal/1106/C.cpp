#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    long long total = 0;

    for (int i = 0, j = N - 1; i < j; i++, j--)
        total += (long long) (A[i] + A[j]) * (A[i] + A[j]);

    cout << total << '\n';
}