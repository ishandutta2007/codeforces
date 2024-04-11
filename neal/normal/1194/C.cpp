#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string YES = "YES", NO = "NO";

string S, T, P;

void solve_case() {
    cin >> S >> T >> P;

    if (S.size() > T.size()) {
        cout << NO << '\n';
        return;
    }

    vector<bool> in_S(T.size(), false);
    size_t index = 0;

    for (char c : S) {
        while (index < T.size() && T[index] != c)
            index++;

        if (index >= T.size()) {
            cout << NO << '\n';
            return;
        }

        in_S[index] = true;
        index++;
    }

    vector<bool> used(P.size(), false);

    for (size_t i = 0; i < T.size(); i++)
        if (!in_S[i]) {
            bool found = false;

            for (size_t j = 0; j < P.size(); j++)
                if (!used[j] && T[i] == P[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }

            if (!found) {
                cout << NO << '\n';
                return;
            }
        }

    cout << YES << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}