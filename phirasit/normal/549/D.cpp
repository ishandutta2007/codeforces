#include <stdio.h>

const int N = 110;

char str[N][N];
int arr[N][N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n;i++) {
    scanf("%s", str[i]);
    for(int j = 0;j < m;j++) {
      arr[i][j] = 0;
    }
  }
  int ans = 0;
  for(int i = n-1;i >= 0;i--) {
    for(int j = m-1;j >= 0;j--) {
      int val = (str[i][j] == 'W' ? 1 : -1);
      if(arr[i][j] != val) {
        ans++;
        int x = val - arr[i][j];
        for(int ii = 0;ii <= i;ii++) {
          for(int jj = 0;jj <= j;jj++) {
            arr[ii][jj] += x;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}