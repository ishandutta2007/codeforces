#include <bits/stdc++.h>
using namespace std;
const int md=998244353,MX=2020;
int n,it,cc,j,z,r,u[2][MX],c[2][MX],v[2][MX],st[MX],vst[MX],pw2[MX];
char s[MX];
bool ok;
void dfs(int i, int j, int cur, int val) {
  u[i][j]=it;
  c[i][j]=cur;
  v[i][j]=val;
  if (i==0) {
    if (u[0][n-1-j]!=it) dfs(0,n-1-j,cur,val);
     else if (v[0][n-1-j]!=val) ok=false;
    if (s[j]=='0') {
      if (j<it) {
        if (u[1][j]!=it) dfs(1,j,cur,val); else if (v[1][j]!=val) ok=false;
      } else if (st[cur]!=it) {
        st[cur]=it;
        vst[cur]=val;
      } else if (vst[cur]!=val) ok=false;
    } else if (s[j]=='1') {
      if (j<it) {
        if (u[1][j]!=it) dfs(1,j,cur,1-val); else if (v[1][j]!=1-val) ok=false;
      } else if (st[cur]!=it) {
        st[cur]=it;
        vst[cur]=val^1;
      } else if (vst[cur]!=(val^1)) ok=false;
    }
  } else {
    if (u[1][it-1-j]!=it) dfs(1,it-1-j,cur,val);
     else if (v[1][it-1-j]!=val) ok=false;
    if (s[j]=='0') {
      if (u[0][j]!=it) dfs(0,j,cur,val); else if (v[0][j]!=val) ok=false;
    } else if (s[j]=='1') {
      if (u[0][j]!=it) dfs(0,j,cur,1-val); else if (v[0][j]!=1-val) ok=false;
    }
  }
}
int main() {
  scanf("%s",s);
  n=strlen(s);
  reverse(s,s+n);
  for (pw2[0]=j=1; j<MX; j++) pw2[j]=(pw2[j-1]*2)%md;
  for (it=1; it<n; it++) {
    ok=true;
    cc=1;
    dfs(0,n-1,cc,1);
    if (st[cc]==it && vst[cc]!=0) ok=false;
    st[cc]=it;
    if (u[1][it-1]==it) {
      if (v[0][n-1]!=v[1][it-1]) ok=false;
    } else {
      ++cc;
      dfs(1,it-1,cc,1);
      if (st[cc]==it && vst[cc]!=0) ok=false;
      st[cc]=it;
    }
    for (j=0; j<n-1; j++) if (ok && u[0][j]!=it) {
      ++cc; dfs(0,j,cc,1);
    }
    for (j=0; j<it-1; j++) if (ok && u[1][j]!=it) {
      ++cc; dfs(1,j,cc,1);
    }
    if (ok) {
      for (z=0, j=1; j<=cc; j++) if (st[j]!=it) z++;
      r=(r+pw2[z])%md;
    }
  }
  printf("%d\n",r);
  return 0;
}