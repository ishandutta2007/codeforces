#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
string S;

void solve_case() {
    cin >> N >> K >> S;
    string goal = "";

    for (int k = 0; k < K - 1; k++)
        goal += "()";

    goal += string(N / 2 - (K - 1), '(');
    goal += string(N / 2 - (K - 1), ')');
    assert((int) goal.size() == N);
    vector<pair<int, int>> ops;

    for (int i = 0; i < N; i++)
        if (S[i] != goal[i]) {
            bool found = false;

            for (int j = i + 1; j < N; j++)
                if (S[j] == goal[i]) {
                    ops.emplace_back(i, j);
                    reverse(S.begin() + i, S.begin() + j + 1);
                    found = true;
                    break;
                }

            assert(found);
        }

    cout << ops.size() << '\n';

    for (pair<int, int> op : ops)
        cout << op.first + 1 << ' ' << op.second + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}