#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, H;
vector<int> P;

void solve_case() {
    cin >> H >> N;
    P.resize(N);

    for (int &p : P)
        cin >> p;

    int answer = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        j = i + 1;

        while (j < N && P[j - 1] == P[j] + 1)
            j++;

        if (P[j - 1] > 1 && (j - i) % 2 == (i == 0 ? 0 : 1))
            answer++;
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