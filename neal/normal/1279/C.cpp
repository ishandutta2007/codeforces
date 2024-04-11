#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M;
vector<int> A, B;
vector<int> location, order;

void run_case() {
    cin >> N >> M;
    A.resize(N);
    B.resize(M);

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    for (auto &b : B) {
        cin >> b;
        b--;
    }

    location.assign(N, -1);

    for (int i = 0; i < N; i++)
        location[A[i]] = i;

    order.assign(N, INF);

    for (int i = 0; i < M; i++)
        order[B[i]] = i;

    long long total = 0;
    int maximum_loc = -1;

    for (int i = 0; i < M; i++) {
        int b = B[i];
        int loc = location[b];

        if (loc <= maximum_loc) {
            total++;
            continue;
        }

        maximum_loc = loc;
        int front = loc - i;
        total += 2 * front + 1;
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}