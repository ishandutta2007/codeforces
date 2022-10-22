#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

bool query(int x1, int y1, int x2, int y2) {
  cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
  int flg;
  cin>>flg;
  return flg != 0;
}

int main()
{
  int n;
  cin>>n;
  vector<vecint> table(n, vecint(n, 0));
  table[0][0] = 1;
  table[n-1][n-1] = 0;
  for (int x = 2; x < n; x += 2) {
    int sx = x-2 + 1;
    int tx = x + 1;
    int y = 1;
    bool same = query(sx, y, tx, y);
    if (same) {
      table[x][0] = table[x-2][0];
    } else {
      table[x][0] = 1-table[x-2][0];
    }
  }
  for (int y = 2; y < n; y += 2) {
    int sy = y-2 + 1;
    int ty = y + 1;
    for (int x = 0; x < n; x += 2) {
      if (y == n-1 && x == n-1) break;
      int qx = x + 1;
      bool same = query(qx, sy, qx, ty);
      if (same) {
        table[x][y] = table[x][y-2];
      } else {
        table[x][y] = 1-table[x][y-2];
      }
    }
  }
  for (int y = 1; y < n; y += 2) {
    int sy = y-1 + 1;
    int ty = y + 1;
    for (int x = 1; x < n; x += 2) {
      int sx = x-1 + 1;
      int tx = x + 1;
      bool same = query(sx, sy, tx, ty);
      if (same) {
        table[x][y] = table[x-1][y-1];
      } else {
        table[x][y] = 1-table[x-1][y-1];
      }
    }
  }
  for (int x = 3; x < n; x += 2) {
    int sx = x-2 + 1;
    int tx = x + 1;
    int y = 1;
    bool same = query(sx, y, tx, y);
    if (same) {
      table[x][0] = table[x-2][0];
    } else {
      table[x][0] = 1-table[x-2][0];
    }
  }
  bool same = query(2, 1, 3, 2);
  if (same) {
    table[2][1] = table[1][0];
  } else {
    table[2][1] = 1-table[1][0];
  }
  same = query(1, 2, 3, 2);
  if (same) {
    table[0][1] = table[2][1];
  } else {
    table[0][1] = 1-table[2][1];
  }
  for (int x = 4; x < n; x += 2) {
    int sx = x-2 + 1;
    int tx = x + 1;
    bool same = query(sx, 2, tx, 2);
    if (same) {
      table[x][1] = table[x-2][1];
    } else {
      table[x][1] = 1-table[x-2][1];
    }
  }
  for (int y = 2; y < n; ++y) {
    for (int x = (y+1)%2; x < n; x += 2) {
      int qx = x + 1;
      int sy = y-2 + 1;
      int ty = y + 1;
      bool same = query(qx, sy, qx, ty);
      if (same) {
        table[x][y] = table[x][y-2];
      } else {
        table[x][y] = 1-table[x][y-2];
      }
    }
  }
  bool allsame = true;
  bool parity = false;
  vector<int> clr;
  REP(i,2*n-1) {
    int x = 0;
    int y = i;
    if (i >= n) {
      x += i-(n-1);
      y -= i-(n-1);
    }
    clr.push_back(table[x][y]);
    while (x < n-1 && y > 0) {
      if (table[x][y] != table[x+1][y-1]) {
        int sx = x + 1;
        int sy = y-1 + 1;
        int tx = x+2 + 1;
        int ty = y + 1;
        if (x == n-2) {
          --sx; --tx;
        }
        bool same = query(sx, sy, tx, ty);
        bool now = table[sx-1][sy-1] == table[tx-1][ty-1];
        if (same != now) {
          parity = true;
        }
        allsame = false;
        break;
      }
      ++x;
      --y;
    }
    if (!allsame) break;
  }
  if (allsame) {
    int k = clr.size();
    for (int ofs = 0; ofs < k-3; ++ofs) {
      bool esame = clr[ofs] == clr[ofs+2];
      bool osame = clr[ofs+1] == clr[ofs+3];
      if (esame == osame) {
        int x = 0;
        int y = ofs;
        if (y >= n) {
          x += y - (n-1);
          y = n-1;
        }
        int x2 = 0;
        int y2 = ofs+3;
        if (y2 >= n) {
          x2 += y2 - (n-1);
          y2 = n-1;
        }
        bool same = query(x+1, y+1, x2+1, y2+1);
        bool edgsame = clr[ofs] == clr[ofs+3];
        parity = same != edgsame;
        break;
      }
    }
  }
  if (parity) {
    REP(i,n)REP(j,n) {
      if((i+j)%2) table[i][j] = 1-table[i][j];
    }
  }
  cout<<"!"<<endl;
  REP(i,n) {
    REP(j,n) cout<<table[i][j];
    cout<<endl;
  }
  return 0;
}