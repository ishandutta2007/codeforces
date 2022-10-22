#include <bits/stdc++.h>
using namespace std;

long long N, V[4005], D[4005], P[4005];
bool left1[4005];
vector<int> V1;

void cry(int x, int volume, bool decrease) {
    //printf("kid %d cries with volume %d\n", x + 1, volume);
    for (int i = x + 1; i < N; i++) {
        if (left1[i]) continue;
        P[i] -= volume;
        if (decrease) volume--;
        if (volume == 0) break;
    }
    for (int i = x + 1; i < N; i++) {
        if (P[i] < 0 && !left1[i]) {
            left1[i] = 1;
            cry(i, D[i], 0);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d%d", &V[i], &D[i], &P[i]);
    for (int i = 0; i < N; i++) {
        if (left1[i]) continue;
        V1.push_back(i);
        cry(i, V[i], 1);
    }
    printf("%d\n", V1.size());
    for (int i = 0; i < V1.size(); i++) {
        if (i) printf(" ");
        printf("%d", V1[i] + 1);
    }
    printf("\n");
}