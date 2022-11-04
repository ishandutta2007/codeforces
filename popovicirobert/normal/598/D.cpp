#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

string mat[MAXN + 1];
int viz[MAXN + 1][MAXN + 1];

int dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

inline int check(int l, int c) {
    int cnt = 0;
    for(int i = 0; i < 4; i++)
        if(mat[l + dl[i]][c + dc[i]] == '*')
           cnt++;
    return cnt;
}

int sum[MAXN * MAXN + 1];
int nr;

void dfs(int l, int c) {
   viz[l][c] = nr;
   sum[nr] += check(l, c);
   for(int i = 0; i < 4; i++)
     if(viz[l + dl[i]][c + dc[i]] == 0 && mat[l + dl[i]][c + dc[i]] == '.')
        dfs(l + dl[i], c + dc[i]);
}


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, l, c, j;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
      cin >> mat[i];
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++)
        if(viz[i][j] == 0 && mat[i][j] == '.') {
          nr++;
          dfs(i, j);
        }
    while(k > 0) {
        k--;
        cin >> l >> c;
        l--;
        c--;
        cout << sum[viz[l][c]] << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}