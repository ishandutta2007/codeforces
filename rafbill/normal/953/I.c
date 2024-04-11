#include <stdio.h>
#include <string.h>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define FORU(i,j,k) for(int i = (j); i <= (k); ++i)
#define FORD(i,j,k) for(int i = (j); i >= (k); --i)

int E[1440];

int main(){
  int n;
  scanf("%d", &n);
  FOR(i,n) {
    int h,m; scanf("%d:%d", &h, &m);
    E[60*h+m]=1;
  }
  int ans = 0;
  int cur = 0;
  FOR(i,10000) {
    cur += 1;
    if(E[i%1440]) cur = 0;
    if(cur>ans) ans = cur;
  }
  printf("%02d:%02d\n", ans/60, ans%60);
  return 0;
}