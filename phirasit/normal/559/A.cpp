#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 6;

int a[N];

int sum(int x, int y) {
  int ans = 0;
  for(int i = 0;i < y;i++) {
    ans += x + i + 1;
  }
  return ans;
}
int main() {
  for(int i = 0;i < N;i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  if(a[1] > a[5]) {
    swap(a[1], a[5]);
    swap(a[2], a[4]);
  }
  ans += sum(a[0], a[1]);
  ans += sum(a[3], a[4]);
  ans += (a[5] - a[1] - 1) * (a[0] + a[1]);
  ans = 2 * ans + a[0] + a[3];
  printf("%d\n", ans);
  return 0;
}