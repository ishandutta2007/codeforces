#include <bits/stdc++.h>
using namespace std;
const int MX=300300,md=998244353;
int n,m,i,j,pos,cnt,r,le[MX],up[MX],pw2[MX],z[MX];
char s[MX];
int calc(int cur) {
  int r=z[cnt-2];
  if (cnt>cur) {
    if (cur&1) r+=md-z[cnt-cur-1]; else r+=z[cnt-cur-1];
    if (r>=md) r-=md;
  }
  return r;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s+i*m);
  for (i=0; i<n; i++) for (j=0; j<m; j++, pos++) if (s[pos]=='o') {
    le[pos]=up[pos]=1;
    if (j>0) le[pos]+=le[pos-1];
    if (i>0) up[pos]+=up[pos-m];
    cnt++;
  }
  for (pw2[0]=z[0]=i=1; i<=cnt; i++) {
    pw2[i]=(pw2[i-1]*2)%md;
    z[i]=(pw2[i]+md-z[i-1])%md;
  }
  for (i=0; i<pos; i++) {
    if (le[i]>=2) r=(r+calc(le[i]))%md;
    if (up[i]>=2) r=(r+calc(up[i]))%md;
  }
  printf("%d\n",r);
  return 0;
}