#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 550

using namespace std;

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0} , {0, -1} };
int n, m, k, d = 0, sl = 0;
string s[N];

void RES() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == '#') cout << "#";
            if(s[i][j] == '.') cout << "X";
            if(s[i][j] == 'Q') cout << ".";
        }
        cout << endl;
    }
    exit(0);
}

void DFS(int u, int v) {
    d++;
    s[u][v] = 'Q';
    if(d == sl - k)
        RES();
    for(int i = 0 ; i < 4; i++) {
        int x = u + dir[i][0];
        int y = v + dir[i][1];
        if(s[x][y] == '.')
            DFS(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> k;
    for(int i = 0; i <= m + 1; i++) s[0] += '#', s[n + 1] += '#';
    for(int i = 1; i <= n; i++) {
        cin >> s[i], s[i] = '#' + s[i] + '#';
        for(int j = 1; j <= m; j++) if(s[i][j] == '.') sl++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        if(s[i][j] == '.')
            DFS(i, j);
    return 0;
}