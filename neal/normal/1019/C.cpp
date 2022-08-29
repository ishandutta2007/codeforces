#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1e6 + 5;

int N, M;
vector<int> parents[N_MAX], children[N_MAX];
bool skip[N_MAX], to_solve[N_MAX], in_group[N_MAX];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        children[a].push_back(b);
        parents[b].push_back(a);
    }

    for (int v = 0; v < N; v++)
        if (!skip[v]) {
            to_solve[v] = true;
            skip[v] = true;

            for (int c : children[v])
                skip[c] = true;
        }

    int G = 0;

    for (int v = N - 1; v >= 0; v--)
        if (to_solve[v]) {
            bool has_parent = false;

            for (int p : parents[v])
                has_parent |= in_group[p];

            if (!has_parent) {
                in_group[v] = true;
                G++;
            }
        }

    printf("%d\n", G);
    int index = 0;

    for (int v = 0; v < N; v++)
        if (in_group[v])
            printf("%d%c", v + 1, index++ < G - 1 ? ' ' : '\n');

    return 0;
}