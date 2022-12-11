#include <stdio.h>

const int N = 200010;

int arr[N];
int ans[N];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    scanf("%d", &arr[i]);
  }
  for(int i = 1;i < n;i++) {
    int ls = 1;
    int end = n;
    while(ls <= end) {
      int div = (i - 1) / ls;
      int nx;
      if(div > 0) {
        nx = (i - 1) / div;
      }else {
        nx = n;
      }
      if(nx > end) {
        nx = end;
      }
      int p = (i-1) / ls;
      if(arr[i] < arr[p]) {
        ans[ls]++;
        ans[nx+1]--;
      }
      ls = nx + 1;
    }
  }
  for(int i = 1;i < n;i++) {
    ans[i] += ans[i-1];
    printf("%d ", ans[i]);
  }
  printf("\n"); 
  return 0;
}