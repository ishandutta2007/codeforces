#include <bits/stdc++.h>
using namespace std;
int t,n,m,cnt   ;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    cnt=n+1-(n+1)/2;
    printf("%d\n",m/cnt);
  }
  return 0;
}