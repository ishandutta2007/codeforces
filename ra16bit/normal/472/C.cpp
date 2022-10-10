#include <cstdio>
#include <string>
using namespace std;
int n,i,x;
char s[55];
string st[100100][2],best;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%s",s); st[i][0]=s;
    scanf("%s",s); st[i][1]=s;
    if (st[i][0]>st[i][1]) swap(st[i][0],st[i][1]);
  }
  best="";
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    if (st[x][0]<best) {
      if (st[x][1]<best) { puts("NO"); return 0; }
      best=st[x][1];
    } else best=st[x][0];
  }
  puts("YES");
  return 0;
}