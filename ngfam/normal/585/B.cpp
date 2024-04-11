#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int f[3][N];
int blocked[N + N + N][N + N + N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int nTest;
  cin >> nTest;

  while(nTest--) {
    int n, k;
    cin >> n >> k;

    memset(blocked, 0, sizeof blocked);

    int px = 0, py = 0;

    string board[3];
    for(int i = 0; i < 3; ++i) {
      cin >> board[i];
      for(int j = 0; j < n; ++j) {
        if(board[i][j] == 's') {
          px = i;
          py = j;
          continue;
        }
        if(board[i][j] != '.') {
          blocked[i][j] = 1; /// j at time of 0
          blocked[i][j + 1] = 1;
          blocked[i][j + 2] = 1;
        }
      }
    }

    memset(f, 0, sizeof f);

    f[px][py] = 1;
    queue < pair < int, int > > que;
    que.emplace(px, py);

    bool flag = false;

    int dx[3] = {-1, 0, 1};

    while(!que.empty()) {
      int x = que.front().first, y = que.front().second;
      que.pop();
      if(y == n) {
        flag = true;
        break;
      }



      for(int d = 0; d < 3; ++d) {
        int nx = x + dx[d], ny = y + 1;
        if(nx < 0 || nx >= 3) continue;
        if(blocked[x][ny * 2 + ny - 2]) continue;
        if(f[nx][ny] || blocked[nx][ny + 2 * ny]) continue;
        f[nx][ny] = 1;
        que.emplace(nx, ny);
      }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}