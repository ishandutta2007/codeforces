#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,i,j,rt,a[505][505],c[1010],ans[1010],k[505],kk[505],u[505];
int solve(int le, int ri) {
  if (le==ri) return k[le];
  int cur=++n,cnt=le;
  for (int i=le+1; i<=ri; i++) c[n]=max(c[n],a[k[le]][k[i]]);
  vector<int> b;
  for (int i=le; i<=ri; i++) if (u[i]!=n) {
    b.push_back(cnt);
    kk[cnt++]=k[i];
    u[i]=n;
    for (int j=i+1; j<=ri; j++) if (u[j]!=n && a[k[i]][k[j]]!=c[cur]) {
      kk[cnt++]=k[j];
      u[j]=n;
    }
  }
  for (int i=le; i<=ri; i++) k[i]=kk[i];
  for (int i=0; i<b.size(); i++) {
    int j=solve(b[i],(i+1<b.size())?b[i+1]-1:ri);
    if (j>=0) ans[j]=cur;
  }
  return cur;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
    c[i]=a[i][i];
    k[i]=i;
  }
  rt=solve(1,n);
  printf("%d\n",n);
  for (i=1; i<=n; i++) printf("%d ",c[i]);
  printf("\n%d\n",rt);
  for (i=1; i<=n; i++) if (i!=rt) printf("%d %d\n",i,ans[i]);
  return 0;
}