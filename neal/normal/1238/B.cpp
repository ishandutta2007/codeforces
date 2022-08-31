#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, R;
vector<int> X;

void solve_case() {
    cin >> N >> R;
    X.resize(N);

    for (int &x : X)
        cin >> x;

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    N = X.size();
    int answer = 0;

    for (int i = N - 1; i >= 0; i--)
        if (X[i] - (long long) R * answer > 0)
            answer++;

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