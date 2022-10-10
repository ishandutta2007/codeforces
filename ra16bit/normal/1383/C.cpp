#include <bits/stdc++.h>
using namespace std;
int t,i,j,n,r,it,cc,best,u[22],msk[22],bc[1100100],ok[1100100];
bool c[22][22];
char a[100100],b[100100];
void dfs(int i) {
  u[i]=it;
  for (int j=0; j<20; j++) if ((c[i][j] || c[j][i]) && u[j]!=it) dfs(j);
}
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (i=0; i<20; i++) for (j=0; j<20; j++) c[i][j]=false;
	scanf("%s",a);
	scanf("%s",b);
	for (i=0; i<n; i++) if (a[i]!=b[i]) c[a[i]-'a'][b[i]-'a']=true;
    for (cc=i=0; i<20; i++) {
      if (u[i]!=it) { ++cc; dfs(i); }
	  for (msk[i]=j=0; j<20; j++) if (c[i][j]) msk[i]|=(1<<j);
    }
    ok[0]=it; best=0;
    for (i=1; i<(1<<20); i++) {
      bc[i]=bc[i/2]+(i&1);
      for (j=0; j<20; j++) if (((i>>j)&1) && ok[i^(1<<j)]==it && (msk[j]&i)==0) ok[i]=it;
      if (ok[i]==it) best=max(best,bc[i]);
    }
    printf("%d\n",40-best-cc);
  }
  return 0;
}