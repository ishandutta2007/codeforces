#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,cur,res,w[505],k[505];
char s[505];
int ask() {
  printf("? ");
  puts(s);
  fflush(stdout);
  int x;
  scanf("%d",&x);
  return x;
}
bool cmp(int i, int j) {
  return w[i]<w[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) s[i]='0';
  for (i=0; i<m; i++) {
    s[i]='1';
    w[i]=ask();
    s[i]='0';
    k[i]=i;
  }
  sort(k,k+m,cmp);
  for (res=j=0; j<m; j++) {
    i=k[j];
    s[i]='1';
    cur=ask();
    if (cur==res+w[i]) res=cur; else s[i]='0';
  }
  printf("! %d\n",res);
  fflush(stdout);
  return 0;
}