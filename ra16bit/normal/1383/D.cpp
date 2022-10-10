#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,x,y,r[277],c[277],a[277][277],ans[277][277],fi,fr,qx[277*277],qy[277*277],le[277],ri[277],up[277],dn[277];
bool u[277][277],ok;
void add(int i, int j) {
  //printf(" try add %d %d\n",i,j);
  if (i<0 || j<0 || i>=n || j>=m || ans[i][j]!=0 || u[i][j]) return;
  if (le[i]!=j+1 && ri[i]!=j-1) return;
  if (up[j]!=i+1 && dn[j]!=i-1) return;
  //puts(" added");
  u[i][j]=true;
  qx[fr]=i;
  qy[fr++]=j;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    r[i]=max(r[i],a[i][j]);
    c[j]=max(c[j],a[i][j]);
  }
  sort(r,r+n);
  sort(c,c+m);
  //for (i=0; i<n; i++) printf("%d,",r[i]); puts("r");
  //for (i=0; i<m; i++) printf("%d,",c[i]); puts("c");
  for (i=0; i<n; i++) le[i]=ri[i]=-10;
  for (i=0; i<m; i++) up[i]=dn[i]=-10;
  for (i=n-1, j=m-1, k=n*m; k>0; k--) if (i>=0 && j>=0 && r[i]==k && c[j]==k) {
    if (le[i]!=-10) { puts("-1"); return 0; }
    if (up[j]!=-10) { puts("-1"); return 0; }
    //printf("set %d at %d,%d\n",k,i,j);
    ans[i][j]=k;
    le[i]=ri[i]=j;
    up[j]=dn[j]=i;
    add(i-1,j);
    add(i,j-1);    
    add(i+1,j);
    add(i,j+1);
    --i; --j;
  } else if (i>=0 && r[i]==k) {
    le[i]=ri[i]=j+1;
    //printf("setx %d at %d,%d\n",k,i,j+1);
    if (i==up[j+1]-1) --up[j+1]; else if (i==dn[j+1]+1) ++dn[j+1]; else { puts("-1"); return 0; }
    ans[i][j+1]=k;
    add(i-1,j+1);
    add(i,j);    
    add(i+1,j+1);
    add(i,j+2);
    --i;
  } else if (j>=0 && c[j]==k) {
    up[j]=dn[j]=i+1;
    if (j==le[i+1]-1) --le[i+1]; else if (j==ri[i+1]+1) ++ri[i+1]; else { puts("-1"); return 0; }
    ans[i+1][j]=k;
    //printf("sety %d at %d,%d\n",k,i+1,j);
    add(i,j);
    add(i+1,j-1);    
    add(i+2,j);
    add(i+1,j+1);
    --j;
  } else {
    ok=false;
    while (fi<fr) {
      x=qx[fi];
      y=qy[fi++];
      if (ans[x][y]!=0) continue;
      ans[x][y]=k;
      ok=true;
      //printf("setq %d at %d,%d\n",k,x,y);
      if (x==up[y]-1) --up[y]; else if (x==dn[y]+1) ++dn[y]; else { puts("-1"); return 0; }
      if (y==le[x]-1) --le[x]; else if (y==ri[x]+1) ++ri[x]; else { puts("-1"); return 0; }
      add(x-1,y);
      add(x,y-1);    
      add(x+1,y);
      add(x,y+1);
      break;
    }
    if (!ok) { puts("-1"); return 0; }
  }
  for (i=0; i<n; i++,puts("")) for (j=0; j<m; j++) printf("%d ",ans[i][j]);
  return 0;
}