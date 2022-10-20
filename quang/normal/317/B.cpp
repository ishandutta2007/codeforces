#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100

using namespace std;

int n, t;
int sl[2 * N + 20][2 * N + 20];

void Loang(int x, int y, int val) {
    sl[x][y] += val;
    int p = sl[x][y];
    sl[x][y] %= 4;
    if(p < 4) return ;
    Loang(x + 1, y, p / 4);
    Loang(x - 1, y, p / 4);
    Loang(x, y + 1, p / 4);
    Loang(x, y - 1, p / 4);
}

int main() {
    //fi, fo;
    scanf("%d%d", &n, &t);
    Loang(N, N, n);
    for(int i = 1; i <= t; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(abs(x) > 100 || abs(y) > 100) cout << 0 << endl;
        else cout << sl[x + N][y + N] << endl;
    }
    return 0;
}