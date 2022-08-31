#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S >> T;
    int a_count = count(S.begin(), S.end(), 'a') + count(T.begin(), T.end(), 'a');

    if (a_count % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> A, B;

    for (int i = 0; i < N; i++)
        if (S[i] != T[i])
            (S[i] == 'a' ? A : B).push_back(i);

    assert((A.size() + B.size()) % 2 == 0);
    vector<pair<int, int>> operations;

    if (A.size() % 2 != 0) {
        operations.emplace_back(A.back(), A.back());
        B.push_back(A.back());
        A.pop_back();
    }

    for (int i = 0; i < (int) A.size(); i += 2)
        operations.emplace_back(A[i], A[i + 1]);

    for (int i = 0; i < (int) B.size(); i += 2)
        operations.emplace_back(B[i], B[i + 1]);

    cout << operations.size() << '\n';

    for (pair<int, int> &p : operations)
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}