#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,a,lst;
bool ok,was;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    was=false;
    ok=(n==1);
    for (lst=-5, i=0; i<n; i++) {
      scanf("%d",&a);
      if (a==m) was=true;
      if (a>=m) {
        if (i-lst<=2) ok=true;
        lst=i;
      }
    }
    puts((was && ok)?"yes":"no");
  }
  return 0;
}