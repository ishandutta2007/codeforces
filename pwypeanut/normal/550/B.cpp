#include <bits/stdc++.h>
using namespace std;

int N, L, R, X, arr[20];

int main() {
    scanf("%d%d%d%d", &N, &L, &R, &X);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> V;
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) > 0) V.push_back(arr[j]);
        }
        if (V.size() < 2) continue;
        sort(V.begin(), V.end());
        int sum = 0;
        for (int j = 0; j < V.size(); j++) sum += V[j];
        if (sum >= L && sum <= R && V.back() - V.front() >= X) ans++;
    }
    printf("%d\n", ans);
}