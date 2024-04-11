#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,i,j,p,x,cur,cnt,tmp,res,a[111][111],b[111][111],c[111][111],ind[111];
char s[111];
bool cmp(int x, int y) {
  return b[j][x]-a[i][x]>b[j][y]-a[i][y];
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    for (j=0; j<m; j++) {
      scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
      ind[j]=j;
    }
  }
  for (i=0; i<n; i++) for (j=0; j<n; j++) if (i!=j) {
    sort(ind,ind+m,cmp); cnt=k;
    for (cur=p=0; p<m; p++) {
      x=ind[p];
      if (a[i][x]<b[j][x] && cnt>0) {
        tmp=min(cnt,c[i][x]);
        cur+=(b[j][x]-a[i][x])*tmp;
        cnt-=tmp;
      }
    }
    if (cur>res) res=cur;
  }
  printf("%d\n",res);
  return 0;
}