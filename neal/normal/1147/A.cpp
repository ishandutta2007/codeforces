#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> questions;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    questions.resize(K);

    for (int &q : questions)
        cin >> q;

    vector<int> first_index(N + 1, -1);

    for (int i = K - 1; i >= 0; i--)
        first_index[questions[i]] = i;

    int total = 0;

    for (int i = 1; i <= N; i++)
        if (first_index[i] < 0) {
            int add = 3;

            if (i == 1)
                add--;

            if (i == N)
                add--;

            total += add;
        }

    vector<bool> seen(N + 1, false);

    for (int i = K - 1; i >= 0; i--) {
        if (first_index[questions[i]] == i) {
            if (questions[i] > 1 && !seen[questions[i] - 1])
                total++;

            if (questions[i] < N && !seen[questions[i] + 1])
                total++;
        }

        seen[questions[i]] = true;
    }

    cout << total << '\n';
}