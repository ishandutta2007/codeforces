#include <stdio.h>

const int N = 100010;

int arr[N];
int n;

void print(int a, int b) {
  if(a > b) {
    return;
  }
  if(a == b) {
    printf("%d", arr[a]);
    return;
  }

  printf("(");
  print(a, b-1);
  printf("->%d)", arr[b]);
}
int main() {
  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    scanf("%d", &arr[i]);
  }
  if(arr[n-1] == 1) {
    printf("NO\n");
    return 0;
  }
  int p;
  for(int i = 0;i < n;i++) {
    if(arr[i] == 0) {
      p = i;
      break;
    }
  }
  if(p == n-2) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if(n == 1) {
    printf("0\n");
  }else if(p == n-1) {
    print(0, n-2);
    printf("->0\n");
  }else {
    if(p > 0) {
      printf("((");
      print(0, p-1);
      printf("->0)->");
    }else {
      printf("(0->");
    }
    print(p+1, n-2);
    printf(")");
    printf("->0\n");
  }
  return 0;
}