#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2000;

int used[N][N];

bool solve(int l, int r, int left, int cnt) {
    if (left == 0) return (l == r);
    bool ans = true;
    int d = (r - l + cnt) / cnt;
    for (int color = 1; l <= r; color++) {
        int g = min(l + d - 1, r);
        for (int i = l; i <= g; i++) used[left][i] = color;
        ans &= solve(l, g, left - 1, cnt);
        l = g + 1;
    }
    return ans;
}

int main() {
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    bool res = solve(1, n, d, k);
    if (!res) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= d; i++) for (int j = 1; j <= n; j++) {
        printf("%d", used[i][j]);
        if (j == n) printf("\n"); else printf(" ");
    }
    return 0;
}