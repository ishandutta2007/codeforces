#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M, Q;
vector<int> P, A;
vector<int> parent;
vector<vector<int>> ancestor;
vector<int> at_least;

int largest_bit(int x) {
    return 31 - __builtin_clz(x);
}

int get_kth_ancestor(int v, int k) {
    for (int i = 0; 1 << i <= k; i++)
        if (k & 1 << i) {
            v = ancestor[i][v];

            if (v < 0)
                break;
        }

    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    P.resize(N);
    vector<int> location(N, -INF);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        location[P[i]] = i;
    }

    A.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
        A[i] = location[A[i]];
    }

    parent.resize(M);
    vector<int> closest(N, -INF);

    for (int i = M - 1; i >= 0; i--) {
        parent[i] = closest[(A[i] + 1) % N];
        closest[A[i]] = i;
    }

    ancestor.assign(largest_bit(N) + 1, vector<int>(M));
    ancestor[0] = parent;

    for (int k = 0; k < largest_bit(N); k++)
        for (int i = 0; i < M; i++)
            ancestor[k + 1][i] = ancestor[k][i] < 0 ? -INF : ancestor[k][ancestor[k][i]];

    at_least.assign(M + 1, INF);

    for (int i = M - 1; i >= 0; i--) {
        at_least[i] = at_least[i + 1];
        int anc = get_kth_ancestor(i, N - 1);

        if (anc >= 0)
            at_least[i] = min(at_least[i], anc + 1);
    }

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
        cout << (R >= at_least[L] ? 1 : 0);
    }

    cout << '\n';
}