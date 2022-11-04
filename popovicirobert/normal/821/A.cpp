#include <bits/stdc++.h>


using namespace std;

int mat[52][52];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,j,n,l,c;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
           cin >> mat[i][j];
    for(i = 1; i <= n; i++)
       for(j = 1; j <= n; j++)
        if(mat[i][j] != 1){
          int cnt = 0;
          for(l = 1; l <= n && cnt == 0; l++)
            for(c = 1; c <= n && cnt == 0; c++)
              if(mat[i][j] == mat[l][j] + mat[i][c])
                cnt = 1;
          if(cnt == 0) {
              cout << "No";
              return 0;
          }
      }
              cout << "Yes";
    //cin.close();
    //cout.close();
    return 0;
}