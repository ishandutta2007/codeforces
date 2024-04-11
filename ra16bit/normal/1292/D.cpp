#include <bits/stdc++.h>
using namespace std;
const int MX=5002,MY=707,MZ=MX*MY;
int n,m,num,i,ii,j,jj,z,prv,a[MX],b[MY],cnt[MX][MY],k[MX],w[MX],nw[MX],f[MZ];
long long c[MZ],s[MZ],res;
vector<int> g[MZ];
bool cmp(int i, int j) {
  if (w[i]!=w[j]) return w[i]<w[j];
  return cnt[i][z]<cnt[j][z];
}
void dfs(int i) {
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k);
    c[i]+=c[k];
    s[i]+=s[k]+c[k]*f[k];
  }
  //printf("%d = %d %d\n",i,int(c[i]),int(s[i]));
}
void solve(int i, long long v) {
  res=min(res,v+s[i]);
  //printf("solve %d = %d %d\n",i,int(v),int(res));
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    solve(k,v+s[i]-s[k]+(n-2*c[k])*f[k]);
  }
}
int main() {
  for (i=2; i<MX; i++) if (!a[i]) {
    b[++m]=i;
    for (j=i; j<MX; j+=i) if (!a[j]) a[j]=m;
  }
  for (i=2; i<MX; i++) {
    for (j=1; j<=m; j++) cnt[i][j]=cnt[i-1][j];
    for (j=i; j>1; j/=b[a[j]]) cnt[i][a[j]]++;
    //z=0;
    //for (j=1; j<=m; j++) z+=cnt[i][j];
    //for (j=1; j<=m; j++) printf("%d ",cnt[i][j]); puts("");
  }
  for (i=0; i<MX; i++) k[i]=i;
  for (z=m; z>0; z--) {
    sort(k,k+MX,cmp);
    for (ii=0; ii<MX; ii++) {
      i=k[ii]; prv=k[ii-1];
      if (ii==0 || w[i]!=w[prv]) {
        if (cnt[i][z]>0) {
          nw[i]=++num;
          f[num]=cnt[i][z];
          g[w[i]].push_back(num); 
        } else nw[i]=w[i];
      } else if (cnt[i][z]!=cnt[prv][z]) {
        nw[i]=++num;
        f[num]=cnt[i][z]-cnt[prv][z];
        g[nw[prv]].push_back(num);
        //printf("%d --> %d [%d]   @ z=%d (%d!=%d) | i=%d prv=%d\n",w[i],num,cnt[prv][z]-cnt[i][z],z,cnt[i][z],cnt[prv][z],i,prv);
        /*for (jj=ii-2; jj>=0; jj--) {
          j=k[jj];
          if (w[j]!=w[i] || cnt[j][z]!=cnt[prv][z]) break;
          w[j]=num;
          //printf("also %d\n",j);
        }*/
      } else nw[i]=nw[prv];
    }
    for (i=0; i<MX; i++) w[i]=nw[i];
  }
  /*for (i=0; i<MX; i++) bck[w[i]]=i;
  for (i=0; i<=num; i++) for (jj=0; jj<g[i].size(); jj++) {
    j=g[i][jj];
    for (z=1; z<=m; z++) f[j]+=cnt[bck[j]][z]-cnt[bck[i]][z];
  }*/
//  for (i=0; i<=num; i++) printf("%d = %d\n",i,f[i]);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&z);
    c[w[z]]++;
  }
  dfs(0);
  res=s[0];
  solve(0,0);
  printf("%I64d\n",res);
  return 0;
}