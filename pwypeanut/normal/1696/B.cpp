#include <bits/stdc++.h>
using namespace std;

int T, N, A[100005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != 0 && (i == 0 || A[i-1] == 0)) ans++;
        }
        printf("%d\n", min(ans, 2));
    }
}