#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int a[8][3];

long long Dis(int x, int y) {
    long long res = 0;
    for(int i = 0; i < 3; i++)
        res += 1ll * (a[x][i] - a[y][i]) * (a[x][i] - a[y][i]);
    return res;
}

long long TVH(int x, int y, int z) {
    long long res = 0;
    for(int i = 0; i < 3; i++) res += 1ll * (a[x][i] - a[y][i]) * (a[x][i] - a[z][i]);
    return res;
}

void DFS(int u) {
    if(u >= 8) {
        long long lmin = Dis(0, 1);
        for(int i = 2; i < 8; i++) lmin = min(lmin, Dis(0, i));
        if(!lmin) return;
        for(int i = 0; i < 8; i++) {
            int p[10];
            int d = 0;
            for(int j = 0; j < 8; j++) {
                if(j == i) continue;
                long long kc = Dis(i, j);
                if(kc == lmin) p[++d] = j;
            }
            if(d != 3) return;
            for(int j = 1; j <= 2; j++)
            for(int k = j + 1; k <= 3; k++)
            if(TVH(i ,p[j], p[k]))
                return;
        }
        cout << "YES\n";
        for(int i = 0; i < 8; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
        exit(0);
    }
    sort(a[u], a[u] + 3);
    do
        DFS(u + 1);
    while (next_permutation(a[u], a[u] + 3));
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    for(int i = 0; i < 8; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    DFS(1);
    cout << "NO";
    return 0;
}