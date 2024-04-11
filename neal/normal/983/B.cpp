#include <iostream>
using namespace std;

// Create a namespace to avoid naming conflicts.
namespace neal {

const int N_MAX = 5005;

int N;
int numbers[N_MAX];
int segment[N_MAX][N_MAX];
int most[N_MAX][N_MAX];
int Q, L, R;

void solve_problem() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        segment[1][i] = numbers[i];
    }

    for (int level = 2; level <= N; level++) {
        for (int i = 0; i <= N - level; i++) {
            numbers[i] = numbers[i] ^ numbers[i + 1];
            segment[level][i] = numbers[i];
        }
    }

    for (int level = 1; level <= N; level++) {
        for (int i = 0; i <= N - level; i++) {
            most[level][i] = segment[level][i];

            if (level > 1) {
                most[level][i] = max(most[level][i], most[level - 1][i]);
                most[level][i] = max(most[level][i], most[level - 1][i + 1]);
            }
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        L--;
        int level = R - L;
        cout << most[level][L] << '\n';
    }
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    neal::solve_problem();
    return 0;
}