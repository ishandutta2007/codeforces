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

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());

    if (A.size() > 3) {
        cout << -1 << '\n';
        return 0;
    }

    if (A.size() == 1) {
        cout << 0 << '\n';
        return 0;
    }

    if (A.size() == 2) {
        int answer = A[1] - A[0];

        if (answer % 2 == 0)
            answer /= 2;

        cout << answer << '\n';
        return 0;
    }

    if (A.size() == 3) {
        if (A[2] - A[1] != A[1] - A[0])
            cout << -1 << '\n';
        else
            cout << A[1] - A[0] << '\n';
    }
}