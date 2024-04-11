#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

bool mat[MAXN + 1][MAXN + 1];

int main() {
   // fstream cin("B.in");
  //  ofstream cout("B.out");
    int i,j,n,m;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> ch;
            if(ch == 'W')
                mat[i][j] = 0;
            else {
                mat[i][j] = 1;
                cnt++;
            }
        }
    }
    if(cnt == 0) {
        cout << 1;
        return 0;
    }
    int l1 = n + 1, l2 = 0;
    int c1 = m + 1, c2 = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) {
            if(mat[i][j] == 1) {
                l1 = std::min(l1, i);
                c1 = std::min(c1, j);
                l2 = std::max(l2, i);
                c2 = std::max(c2, j);
            }
        }
    int l = std::max(l2 - l1 + 1, c2 - c1 + 1);
    for(i = 1 ; i <= n; i++)
     for(j = 1; j <= m; j++)
       if(i + l <= n + 1 && j + l <= m + 1) {
          int x = 0;
          for(l1 = i; l1 < i + l; l1++)
           for(c1 = j; c1 < j + l; c1++) {
              if(mat[l1][c1] == 1)
                x++;
           }
          if(x == cnt) {
            cout << l * l - cnt;
            return 0;
          }
       }
    cout << -1;
   // cin.close();
   // cout.close();
    return 0;
}