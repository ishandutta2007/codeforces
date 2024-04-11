#include <bits/stdc++.h>
using namespace std;

int n;
char c[55][55];
bool attacked[55][55];
bool result[105][105];


int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%s",c[i]);
  }
  for (int i = -n + 1; i <= n - 1; i++) {
    for (int j = -n + 1; j <= n - 1; j++) {
      if (i !=0 || j != 0) {
        bool can = true;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (c[k][l] == 'o') {
              if (k + i >= 0 && l + j >= 0 && k + i < n && l + j < n) {
                if (c[k+i][l+j] == '.') {
                  can = false;
                  break;
                }
              }
            }
          }
          if (!can) {
            break;
          }
        }
        if (can) {
          result[i+n-1][j+n-1] = true;
          for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
              if (c[k][l] == 'o') {
                if (k + i >= 0 && l + j >= 0 && k + i < n && l + j < n) {
                  attacked[k+i][l+j] = true;
                }
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] == 'x' && !attacked[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < 2*n-1; i++) {
    for (int j = 0;j < 2*n-1;j++) {
      if (i == n-1 && j == n-1) {
        printf("o");
      } else if (result[i][j]) {
        printf("x");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}