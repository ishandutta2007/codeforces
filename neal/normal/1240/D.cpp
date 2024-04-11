#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    vector<int> jumps(N + 1, 0);
    vector<unordered_map<int, int>> closest(N + 1);
    long long answer = 0;

    for (int i = N - 1; i >= 0; i--) {
        auto &closest_next = closest[i + 1];
        int location = closest_next.find(A[i]) != closest_next.end() ? closest_next[A[i]] : N;

        if (location < N) {
            assert(A[i] == A[location]);
            jumps[i] = jumps[location + 1] + 1;
            answer += jumps[i];
        }

        location = min(location + 1, N);
        swap(closest[i], closest[location]);
        closest[i][A[i]] = i;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}