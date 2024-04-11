#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<string> pins(N);

    for (string &pin : pins)
        cin >> pin;

    int changes = 0;

    for (int i = 0; i < N; i++) {
        bool equal = false;

        for (int j = 0; j < N; j++)
            if (i != j && pins[i] == pins[j])
                equal = true;

        if (equal) {
            changes++;

            for (char last = '0'; last <= '9'; last++) {
                pins[i].back() = last;
                bool works = true;

                for (int j = 0; j < N; j++)
                    if (i != j && pins[i] == pins[j]) {
                        works = false;
                        break;
                    }

                if (works)
                    break;
            }
        }
    }

    cout << changes << '\n';

    for (string &pin : pins)
        cout << pin << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}