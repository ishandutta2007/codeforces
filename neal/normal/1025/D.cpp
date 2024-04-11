#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N_MAX = 702;

int N, A[N_MAX];
bool edge[N_MAX][N_MAX];
int8_t can_do_save[N_MAX][N_MAX];

bool can_do(int x, int root) {
    if (x == root)
        return true;

    int8_t &answer = can_do_save[x][root];

    if (answer != -1)
        return answer;

    if (x < root) {
        for (int left = x; left < root; left++)
            if (edge[root][left] && can_do(x, left) && can_do(root - 1, left))
                return answer = true;
    } else {
        for (int right = root + 1; right <= x; right++)
            if (edge[root][right] && can_do(root + 1, right) && can_do(x, right))
                return answer = true;
    }

    return answer = false;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            edge[i][j] = __gcd(A[i], A[j]) > 1;

    memset(can_do_save, -1, sizeof(can_do_save));
    bool answer = false;

    for (int i = 0; i < N; i++)
        if (can_do(0, i) && can_do(N - 1, i)) {
            answer = true;
            break;
        }

    cout << (answer ? "Yes" : "No") << '\n';
    return 0;
}