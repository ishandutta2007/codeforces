#include <bits/stdc++.h>
using namespace std;
int t,x,y;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&x,&y);
    if (x==0 && y==0) { puts("0"); continue; }
    if (x==y) { puts("1"); continue; }
    if ((x&1)==(y&1)) puts("2"); else puts("-1");
  }
  return 0;
}