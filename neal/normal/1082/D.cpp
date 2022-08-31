#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main() {
    scanf("%d", &N);
    A.resize(N);
    int degree_sum = 0;

    for (int &a : A) {
        scanf("%d", &a);
        degree_sum += a;
    }

    if (degree_sum < 2 * (N - 1)) {
        puts("NO");
        return 0;
    }

    vector<int> leaves;

    for (int i = 0; i < N; i++)
        if (A[i] == 1)
            leaves.push_back(i);

    vector<int> path;

    if (!leaves.empty()) {
        path.push_back(leaves.back());
        leaves.pop_back();
    }

    for (int i = 0; i < N; i++)
        if (A[i] > 1)
            path.push_back(i);

    if (!leaves.empty()) {
        path.push_back(leaves.back());
        leaves.pop_back();
    }

    printf("YES %d\n", (int) path.size() - 1);
    printf("%d\n", N - 1);

    for (int i = 0; i + 1 < (int) path.size(); i++) {
        printf("%d %d\n", path[i] + 1, path[i + 1] + 1);
        A[path[i]]--;
        A[path[i + 1]]--;
    }

    for (int leaf: leaves) {
        int parent = -1;

        for (int x : path)
            if (A[x] > 0) {
                parent = x;
                break;
            }

        assert(parent >= 0);
        A[parent]--;
        printf("%d %d\n", leaf + 1, parent + 1);
    }
}