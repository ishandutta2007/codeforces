#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N, M, V;
    cin >> N >> M;
    V = 3 * N;
    vector<bool> matched(V, false);
    vector<int> matching;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (!matched[a] && !matched[b]) {
            matching.push_back(i);
            matched[a] = matched[b] = true;
        }
    }

    if ((int) matching.size() >= N) {
        cout << "Matching" << '\n';

        for (int i = 0; i < N; i++)
            cout << matching[i] + 1 << (i < N - 1 ? ' ' : '\n');

        return;
    }

    cout << "IndSet" << '\n';
    int count = 0;

    for (int i = 0; i < V && count < N; i++)
        if (!matched[i])
            cout << i + 1 << (count++ < N - 1 ? ' ' : '\n');

    assert(count >= N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}