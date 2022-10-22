#include <bits/stdc++.h>
using namespace std;

int N, M, arr[105][105];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);
    int maxi = 0;
    for (int i = 0; i < N; i++) {
        int mini = 1000000000;
        for (int j = 0; j < M; j++) mini = min(mini, arr[i][j]);
        maxi = max(maxi, mini);
    }
    printf("%d\n", maxi);
}