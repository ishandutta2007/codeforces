#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> degree;

int main() {
    scanf("%d %d", &N, &S);
    degree.assign(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        degree[a]++;
        degree[b]++;
    }

    int leaves = 0;

    for (int i = 0; i < N; i++)
        if (degree[i] == 1)
            leaves++;

    printf("%.12lf\n", 2.0 / leaves * S);
}