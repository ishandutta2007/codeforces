#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<int> P(N);

    for (int &p : P) {
        cin >> p;
        p--;
    }

    vector<int> answer(N, -1);

    for (int i = 0; i < N; i++)
        if (answer[i] < 0) {
            int j = i, count = 0;

            do {
                j = P[j];
                count++;
            } while (j != i);

            do {
                answer[j] = count;
                j = P[j];
            } while (j != i);
        }

    for (int i = 0; i < N; i++)
        cout << answer[i] << (i < N - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}