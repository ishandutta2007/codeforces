#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,i,n,q,lft,sum[MX],lst[2][MX*2],l[MX],r[MX],ans[MX],pos[MX];
vector<int> g[MX];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=0; i<q; i++) {
      scanf("%d%d",&l[i],&r[i]);
      g[r[i]].push_back(i);
    }
    sum[0]=MX;
    for (i=0; i<n; i++) {
      if (i&1) {
        sum[i+1]=(s[i]=='+')?-1:1;
      } else {
        sum[i+1]=(s[i]=='+')?1:-1;
      }
      sum[i+1]+=sum[i];
      lst[int(sum[i+1]<sum[i])][sum[i+1]]=i+1;
      for (int j: g[i+1]) {
        if (sum[l[j]-1]==sum[r[j]]) { ans[j]=0; continue; }
        if ((r[j]-l[j])&1) {
          ans[j]=2;
          ++l[j];
        } else ans[j]=1;
        lft=l[j]-1;
        if (sum[r[j]]<sum[lft]) {
          pos[j]=lst[1][sum[lft]-(sum[lft]-sum[r[j]]+1)/2];
        } else {
          pos[j]=lst[0][sum[lft]+(sum[r[j]]-sum[lft]+1)/2];
        }
      }
    }
    for (i=0; i<q; i++) {
      printf("%d\n",ans[i]);
      if (ans[i]>1) printf("%d ",l[i]-1);
      if (ans[i]>0) printf("%d\n",pos[i]);
    }
  }
  return 0;
}