#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int A_MAX = 2005;

int N, K;
int f[A_MAX];
vector<int> A;
vector<bitset<A_MAX>> possible;
vector<int> B;
vector<pair<int, int>> operations;

void generate_B(int mask, int goal, int b) {
    if (mask == 0)
        return;

    if (goal * K < A_MAX && possible[mask][goal * K]) {
        generate_B(mask, goal * K, b + 1);
        return;
    }

    for (int i = 0; i < N; i++)
        if (mask >> i & 1)
            if (goal >= A[i] && possible[mask ^ 1 << i][goal - A[i]]) {
                B[i] = b;
                generate_B(mask ^ 1 << i, goal - A[i], b);
                return;
            }

    assert(false);
}

void generate_operations() {
    while (N > 1) {
        int max_B = *max_element(B.begin(), B.end());
        int x = -1, y = -1;

        for (int i = 0; i < N; i++)
            if (B[i] == max_B) {
                if (x < 0)
                    x = i;
                else
                    y = i;
            }

        assert(x >= 0 && y >= 0);
        operations.emplace_back(A[x], A[y]);
        int new_a = A[x] + A[y];
        int new_b = B[x];

        while (new_a % K == 0) {
            new_a /= K;
            new_b--;
        }

        A.erase(A.begin() + y);
        B.erase(B.begin() + y);
        A.erase(A.begin() + x);
        B.erase(B.begin() + x);
        A.push_back(new_a);
        B.push_back(new_b);
        N--;
    }
}

int main() {
    cin >> N >> K;
    A.resize(N);
    B.assign(N, -1);
    possible.assign(1 << N, {});

    for (int &a : A) {
        cin >> a;
        assert(a % K != 0);
    }

    f[0] = 0;

    for (int a = 1; a < A_MAX; a++)
        f[a] = a % K != 0 ? a : f[a / K];

    possible[0][0] = true;

    for (int mask = 0; mask < 1 << N; mask++) {
        for (int i = 0; i < N; i++)
            if (mask >> i & 1)
                possible[mask] |= possible[mask ^ 1 << i] << A[i];

        for (int a = (A_MAX - 1) / K; a >= 0; a--)
            possible[mask][a] = possible[mask][a] | possible[mask][a * K];
    }

    if (!possible[(1 << N) - 1][1]) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    generate_B((1 << N) - 1, 1, 0);
    generate_operations();

    for (auto &op : operations)
        cout << op.first << ' ' << op.second << '\n';
}