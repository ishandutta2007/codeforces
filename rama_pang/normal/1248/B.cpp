#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(begin(A), end(A));
    lint x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (i + i + 1 < N) y += A[i];
        else x += A[i];
    }

    cout << (x * x + y * y) << "\n";
    return 0;
}