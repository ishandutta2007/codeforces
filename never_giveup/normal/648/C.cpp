#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e2;

bool v[maxn][maxn];

int q[maxn][maxn];

int n, m, sti, stj;

void dfs(int i, int j){
    if (v[i][j])
        return;
    v[i][j] = 1;
    bool is = 0;
    if (i > 0 && !v[i - 1][j])
        is = 1, cout << 'U', dfs(i - 1, j);
    if (i < n - 1 && !v[i + 1][j])
        is = 1, cout << 'D', dfs(i + 1, j);
    if (j > 0 && !v[i][j - 1])
        is = 1, cout << 'L', dfs(i, j - 1);
    if (j < m - 1 && !v[i][j + 1])
        is = 1, cout << 'R', dfs(i, j + 1);
    if (is)
        return;
    if (i > 0 && q[i - 1][j] == 2)
        cout << 'U';
    if (i < n - 1 && q[i + 1][j] == 2)
        cout << 'D';
    if (j > 0 && q[i][j - 1] == 2)
        cout << 'L';
    if (j < m - 1 && q[i][j + 1] == 2)
        cout << 'R';

}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        char c;
        cin >> c;
        if (c == '.')
            q[i][j] = 0, v[i][j] = 1;
        if (c == '*')
            q[i][j] = 1;
        if (c == 'S')
            sti = i, stj = j, q[i][j] = 2;
    }
    dfs(sti, stj);
}