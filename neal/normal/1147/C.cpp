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
    int min_count = 0;

    for (int i = 0; i < N; i++)
        if (A[i] == A[0])
            min_count++;

    cout << (min_count <= N / 2 ? "Alice" : "Bob") << '\n';
}