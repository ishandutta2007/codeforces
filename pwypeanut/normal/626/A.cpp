#include <bits/stdc++.h>
using namespace std;

int N;
char c[205];

int main() {
    scanf("%d", &N);
    scanf("%s", &c);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sumx = 0, sumy = 0;
            for (int k = i; k <= j; k++) {
                if (c[k] == 'U') sumy--;
                if (c[k] == 'D') sumy++;
                if (c[k] == 'L') sumx--;
                if (c[k] == 'R') sumx++;
            }
            if (sumx == 0 && sumy == 0) ans++;
        }
    }
    printf("%d\n", ans);
}