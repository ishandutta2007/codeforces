#include <bits/stdc++.h>
using namespace std;
const int MX=10000100;
int t,n,i,j;
char s[55];
bool a[MX];
bool rec(int l, int tot, int cur) {
  if (tot==0) {
    if (a[cur]) printf("%d\n%d\n",i,cur);
    return a[cur];
  }
  for (int j=l; j+tot<=n; j++) if (rec(j+1,tot-1,cur*10+s[j]-'0')) return true;
  return false;
}
int main() {
  a[1]=true;
  for (i=2; i<MX; i++) if (!a[i]) for (j=i+i; j<MX; j+=i) a[j]=true;
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (i=1; i<=7; i++) if (rec(0,i,0)) break;
  }
  return 0;
}