#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> C, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    C.resize(N);
    T.resize(N);

    for (int i = 0; i < N; i++)
        cin >> C[i];

    for (int i = 0; i < N; i++)
        cin >> T[i];

    if (C.front() != T.front() || C.back() != T.back()) {
        cout << "No" << '\n';
        return 0;
    }

    for (int i = 0; i + 1 < N; i++) {
        C[i] = C[i + 1] - C[i];
        T[i] = T[i + 1] - T[i];
    }

    C.pop_back();
    T.pop_back();
    sort(C.begin(), C.end());
    sort(T.begin(), T.end());
    cout << (C == T ? "Yes" : "No") << '\n';
}