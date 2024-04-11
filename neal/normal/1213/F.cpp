#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
vector<int> P, Q;
vector<int> Q_location;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    P.resize(N);
    Q.resize(N);

    for (int &p : P)
        cin >> p;

    for (int &q : Q)
        cin >> q;

    Q_location.assign(N + 1, -1);

    for (int i = 0; i < N; i++)
        Q_location[Q[i]] = i;

    vector<int> sections;
    int farthest = -1;

    for (int i = 0; i < N; i++) {
        farthest = max(farthest, Q_location[P[i]]);

        if (farthest == i)
            sections.push_back(i + 1);
    }

    if ((int) sections.size() < K) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    string answer(N, '.');
    char current = 'a';

    for (int i = 0, index = 0; i < N; i++) {
        if (index < K - 1 && i == sections[index]) {
            current++;
            index++;
        }

        answer[P[i] - 1] = current;
        // answer[i] = current;
    }

    cout << answer << '\n';
}