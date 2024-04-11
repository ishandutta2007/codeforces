#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,cnt,pos[3030],st[3030];
long long a[1000100],f[15][3030],res;
void solve(int i, int le, int ri) {
  if (le==ri) {
    res=max(res,f[i][m]);
    for (int j=pos[ri]; j>=st[ri]; j--) {
      int cur=j-st[ri]+1;
      if (cur<=m && f[i][m-cur]>=0) res=max(res,a[j]+f[i][m-cur]);
    }
    return;
  }
  int mid=(le+ri)/2,num=i+1;
  for (int j=0; j<=m; j++) f[num][j]=f[i][j];
  for (int i=mid+1; i<=ri; i++) {
    int cur=st[i+1]-st[i];
    for (int j=m; j>=cur; j--) if (f[num][j-cur]>=0) f[num][j]=max(f[num][j],f[num][j-cur]+a[pos[i]]);
    //for (int j=1; j<=m; j++) f[num][j]=max(f[num][j],f[num][j-1]);
  }
  solve(num,le,mid);
  for (int j=0; j<=m; j++) f[num][j]=f[i][j];
  for (int i=le; i<=mid; i++) {
    int cur=st[i+1]-st[i];
    for (int j=m; j>=cur; j--) if (f[num][j-cur]>=0) f[num][j]=max(f[num][j],f[num][j-cur]+a[pos[i]]);
    //for (int j=1; j<=m; j++) f[num][j]=max(f[num][j],f[num][j-1]);
  }
  solve(num,mid+1,ri);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&cnt);
    for (j=0; j<cnt; j++) {
      scanf("%I64d",&a[st[i]+j]);
      if (j) a[st[i]+j]+=a[st[i]+j-1];
    }
    st[i+1]=st[i]+cnt;
    pos[i]=st[i+1]-1;
  }
  f[0][0]=0;
  solve(0,0,n-1);
  printf("%I64d\n",res);
  return 0;
}