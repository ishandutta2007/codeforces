#include <bits/stdc++.h>
using namespace std;

int N, M,ans;
char g[55][55];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", &g[i]);
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M-1; j++) {
            vector<char> V;
            for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++)V.push_back(g[i+k][j+l]);
            sort(V.begin(), V.end());
            if (V[0] == 'a' && V[1] == 'c' && V[2] == 'e' && V[3] == 'f') ans++;
        }
    }
    printf("%d\n", ans);
}