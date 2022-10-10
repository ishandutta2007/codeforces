#include <bits/stdc++.h>
using namespace std;
const int MX=100100,MB=26;
const long long H[2]={31,29},MD[2]={1000000009,1000000007};
int T,n,i,j,prv,cur,y,z,x[MX],fi[MX],lst[MX],where[2][MX],p[MX][17],c[2][MX][17],b[2][MX][MB],num[2],N[2],C[2],sum[2][MX*2];
long long res,prh[2],newh[2],h[2][MX];
map<long long,int> o;
char s[5];
void add(int k, int i, int v) {
  for (; i<=2*N[0]; i=(i<<1)-(i&(i-1))) sum[k][i]+=v;
}
int fsum(int k, int i) {
  int r=0;
  for (; i>0; i&=i-1) r+=sum[k][i];
  return r;
}
void dfs(int i, long long cur0, long long cur1) {
  o[cur0*MD[0]+cur1]=i;
  fi[i]=++T;
  for (int j=0; j<26; j++) if (b[0][i][j]!=0) {
    dfs(b[0][i][j],(cur0*H[0]+j+1)%MD[0],(cur1*H[1]+j+1)%MD[1]);
  }
  lst[i]=++T;
}
int main() {
  for (j=0; j<2; j++) for (h[j][0]=i=1; i<MX; i++) h[j][i]=(h[j][i-1]*H[j])%MD[j];
  scanf("%d",&n);
  for (j=0; j<17; j++) p[1][j]=1;
  num[0]=N[0]=C[0]=where[0][1]=1;
  num[1]=N[1]=C[1]=where[1][1]=1;
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x[i],&y);
    --x[i];
    y=where[x[i]][y];
    scanf("%s",s);
    cur=s[0]-'a';
    if (b[x[i]][y][cur]==0) {
      b[x[i]][y][cur]=++num[x[i]];
      if (x[i]==1) {
        p[num[1]][0]=prv=y;
        for (z=0; z<2; z++) c[z][num[1]][0]=prh[z]=cur+1;
        for (j=1; j<17; j++) {
          for (z=0; z<2; z++) c[z][num[1]][j]=prh[z]=(prh[z]*h[z][1<<(j-1)]+c[z][prv][j-1])%MD[z];
          p[num[1]][j]=prv=p[prv][j-1];
        }
      }
    }
    where[x[i]][++N[x[i]]]=b[x[i]][y][cur];
  }
  dfs(1,0,0);
  add(0,1,1);
  add(0,T,-1);
  add(1,1,1);
  res=1;
  for (i=1; i<=n; i++) {
    y=where[x[i]][++C[x[i]]];
    if (x[i]==0) {
      add(0,fi[y],1);
      add(0,lst[y],-1);
      res+=fsum(1,lst[y])-fsum(1,fi[y]-1);
    } else {
      prh[0]=prh[1]=0;
      for (j=16; j>=0; j--) {
        for (z=0; z<2; z++) newh[z]=(prh[z]*h[z][1<<j]+c[z][y][j])%MD[z];
        auto it=o.find(newh[0]*MD[0]+newh[1]);
        if (it!=o.end()) {
          for (z=0; z<2; z++) prh[z]=newh[z];
          y=p[y][j];
        }
      }
      y=o[prh[0]*MD[0]+prh[1]];
      add(1,fi[y],1);
      res+=fsum(0,lst[y]-1);
    }
    printf("%I64d\n",res);
  }
  return 0;
}