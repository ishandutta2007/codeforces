#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> permutations, positions;

bool valid(int i, int j) {
    int first = permutations[0][i], last = permutations[0][j];

    for (int m = 0; m < M; m++)
        if (positions[m][last] - positions[m][first] != j - i)
            return false;

    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    permutations.assign(M, vector<int>());
    positions.assign(M, vector<int>());

    for (int m = 0; m < M; m++) {
        permutations[m].resize(N);
        positions[m].resize(N + 1);

        for (int i = 0; i < N; i++) {
            scanf("%d", &permutations[m][i]);
            positions[m][permutations[m][i]] = i;
        }
    }

    long long total = 0;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && valid(i, j))
            j++;

        total += j - i;
    }

    printf("%lld\n", total);
}