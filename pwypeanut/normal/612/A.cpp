#include <bits/stdc++.h>
using namespace std;

int N, P, Q, cur;
string S;

int main() {
    scanf("%d%d%d", &N, &P, &Q);
    cin >> S;
    for (int i = 0; i <= 100; i++) {
        int l = N - i * P;
        if (l < 0) continue;
        if (l % Q == 0) {
            int r = l / Q;
            printf("%d\n", i + r);
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < P; k++) {
                    printf("%c", S[cur]);
                    cur++;
                }
                printf("\n");
            }
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < Q; k++) {
                    printf("%c", S[cur]);
                    cur++;
                }
                printf("\n");
            }
            return 0;
        }
    }
    printf("-1\n");
}