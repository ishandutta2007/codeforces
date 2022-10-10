#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,cur,a[3][100100],fin[100100],c[100100];
vector<int> r[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&x,&y);
    if (a[x][y]==0) {
      a[x][y]=i;
      for (j=y-1; j<y+2; j++) if (j>0 && j<=n && a[3-x][j]) r[i].push_back(a[3-x][j]);
    } else {
      fin[a[x][y]]=i;
      a[x][y]=0;
    }
  }
  for (i=1; i<=m; i++) if (fin[i]==0) fin[i]=m+1;
  for (i=1; i<=m; i++) for (j=0; j<r[i].size(); j++) {
    c[max(i,r[i][j])]++;
    c[min(fin[i],fin[r[i][j]])]--;
  }
  for (i=1; i<=m; i++) {
    cur+=c[i];
    puts(cur?"No":"Yes");
  }
  return 0;
}