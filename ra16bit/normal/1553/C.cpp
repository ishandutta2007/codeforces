#include <bits/stdc++.h>
using namespace std;
int t,i,res;
char a[22],b[22];
void solve() {
  int x=0,y=0,rx=5,ry=5;
  for (int i=0; i<10; i++) {
   if (i&1) {
    --ry;
    y+=int(b[i]=='1');
   } else {
    --rx;
    x+=int(b[i]=='1');
   }
   if (x>y+ry || y>x+rx) { res=min(res,i+1); break; }
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",a);
    for (i=0; i<10; i++) if (a[i]=='?') b[i]='0'+int(i&1); else b[i]=a[i];
    res=10;
    solve();
    for (i=0; i<10; i++) if (a[i]=='?') b[i]='1'-int(i&1); else b[i]=a[i];
    solve();
    printf("%d\n",res);
  }
  return 0;
}