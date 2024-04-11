#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int g[6][6], b[6];
long long res = 0;
bool kt[6];

void Try(int u ) {
    if(u > 5) {
        res = max(res, 1ll * g[b[1]][b[2]] + g[b[2]][b[1]] + g[b[2]][b[3]] + g[b[3]][b[2]] + 2 * (g[b[3]][b[4]] + g[b[4]][b[3]] + g[b[4]][b[5]] + g[b[5]][b[4]]));
        return;
    }
    for(int i = 1; i <= 5; i++)
    if(!kt[i]) {
        kt[i] = 1;
        b[u] = i;
        Try(u + 1);
        kt[i] = 0;
    }
}

int main() {
    //fi, fo;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++) cin >> g[i][j];
    Try(1);
    cout <<res;
    return 0;
}