#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, xb, yb, xc, yc;
int v[1008][1008];

void dfs(int x, int y) {
      v[x][y] = 2;
      if (x == xc && y == yc) {cout << "YES"; exit(0);}
      for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                  if (i == 0 && j == 0) continue;

                  int a = x+i, b = y+j;

                  if (a >= 1 && a <= n && b >= 1 && b <= n && v[a][b] == 0) {dfs(a, b);}
            }
      }
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      int x, y; cin >> x >> y;
      v[x][y] = 1;
      for (int i = 1; i <= 1000; i++) {
            for (int j = -1; j <= 1; j++) {
                  for (int k = -1; k <= 1; k++) {
                        int a = x + i*j;
                        int b = y + i*k;

                        if (a >= 1 && a <= n && b >= 1 && b <= n) {v[a][b] = 1;}
                  }
            }
      }

      cin >> xb >> yb >> xc >> yc;

      dfs(xb, yb);
      cout << "NO";

	return 0;
}