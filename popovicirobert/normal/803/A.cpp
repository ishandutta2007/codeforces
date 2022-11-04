#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

bool mat[MAXN + 1][MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k > n * n) {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = i; j <= n && k > 0; j++) {
            if(i != j) {
                if(k >= 2) {
                    k -= 2;
                    mat[i][j] = mat[j][i] = 1;
                }
            }
            else {
                k--;
                mat[i][j] = 1;
            }
        }
    }
    if(k == 0)
       for(i = 1; i <= n; i++) {
         for(j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
         cout << endl;
       }
    else {
       i = n;
       while(mat[i][i] == 0)
         i--;
       mat[i + 1][i + 1] = 1;
       for(i = 1; i <= n; i++) {
         for(j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
         cout << endl;
       }
    }
   // cin.close();
   // cout.close();
    return 0;
}