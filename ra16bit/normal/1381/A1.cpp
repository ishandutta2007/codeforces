#include <bits/stdc++.h>
using namespace std;
int t,n,i,ans,r[400400];
char a[100100],b[100100];
void rot(int pos) {
  r[ans++]=pos+1;
  int i=0,j=pos;
  for (; i<j; i++, j--) {
    a[i]='0'+'1'-a[i];
    a[j]='0'+'1'-a[j];
    swap(a[i],a[j]);
  }
  if (i==j) a[i]='0'+'1'-a[i];
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    ans=0;
    for (i=n-1; i>=0; i--) if (a[i]!=b[i]) {
      if (a[0]==b[i]) rot(0);
      rot(i);
    }
    printf("%d",ans);
    for (i=0; i<ans; i++) printf(" %d",r[i]);
    puts("");
  }
  return 0;
}