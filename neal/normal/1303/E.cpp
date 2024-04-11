#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 405;

int N, M;
string S, T;

void run_case() {
    cin >> S >> T;
    N = S.size();
    M = T.size();

    for (int split = 1; split <= M; split++) {
        vector<int> farthest(split + 1, -MAX);
        farthest[0] = 0;

        for (char c : S) {
            for (int left = split; left >= 0; left--)
                if (farthest[left] >= 0) {
                    if (left < split && T[left] == c)
                        farthest[left + 1] = max(farthest[left + 1], farthest[left]);

                    if (farthest[left] < M - split && T[split + farthest[left]] == c)
                        farthest[left]++;
                }
        }

        if (farthest[split] >= M - split) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}