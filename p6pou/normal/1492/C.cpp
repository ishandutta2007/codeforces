#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int N, M;
char a[MAX_N], b[MAX_N];
int bl[MAX_N], br[MAX_N];
int ans;

int main() {
    scanf("%d%d", &N, &M);
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1, j = 1; i <= N && j <= M; i ++) {
        if (a[i] == b[j]) {
            bl[j ++] = i;
        }
    }
    for (int i = N, j = M; i >= 1 && j >= 1; i --) {
        if (a[i] == b[j]) {
            br[j --] = i;
        }
    }
    for (int i = 1; i < M; i ++) {
        ans = max(ans, br[i + 1] - bl[i]);
    }
    printf("%d\n", ans);
    return 0;
}