#include <bits/stdc++.h>
#define MAXN 50

using namespace std;

int mat[MAXN + 1][MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int val = 1;
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++)
          if(abs(i - (n + 1) / 2) + abs(j - (n + 1) / 2) <= n / 2) {
            mat[i][j] = val;
            val += 2;
          }
    val = 2;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(mat[i][j] > 0)
                cout << mat[i][j] << " ";
            else {
                cout << val << " ";
                val += 2;
            }
        }
        cout << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}