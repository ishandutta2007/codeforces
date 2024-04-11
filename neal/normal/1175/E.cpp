#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int LOG = 19;
const int MAX = 5e5 + 5;

int N, M;
int endpoints[MAX];
int jump[LOG][MAX];

int solve(int x, int y) {
    int count = 0;

    for (int k = LOG - 1; k >= 0; k--)
        if (jump[k][x] < y) {
            x = jump[k][x];
            count += 1 << k;
        }

    if (jump[0][x] < y)
        return -1;

    return count + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        endpoints[L] = max(endpoints[L], R);
    }

    int farthest = 0;

    for (int i = 0; i < MAX; i++) {
        farthest = max(farthest, endpoints[i]);
        jump[0][i] = max(farthest, i);
    }

    for (int k = 0; k + 1 < LOG; k++)
        for (int i = 0; i < MAX; i++)
            jump[k + 1][i] = jump[k][jump[k][i]];

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        cout << solve(X, Y) << '\n';
    }
}