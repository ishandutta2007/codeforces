#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

void solve_case() {
    int N;
    cin >> N;
    vector<int> last(N + 1, -INF);
    int best = INF;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        best = min(best, i - last[a] + 1);
        last[a] = i;
    }

    cout << (best <= N ? best : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}