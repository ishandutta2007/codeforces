#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int ST,MX,n,m,i,ii,j,k,st[9],a[344][344];
long long c[344][344],f[344][344];
string s[9],rst;
char str[9];
void maketransfer(int x, int i, int pos, int y, int len) {
  int nxt=(pos<s[i].length())?(st[i]+pos-1)*2-y:0;
  ++a[x][(len-1)*ST+nxt];
}
int main() {
  scanf("%d%d",&n,&m);
  st[0]=1;
  for (i=0; i<n; i++) {
    scanf("%s",str);
    s[i]=str;
    st[i+1]=st[i]+s[i].length()-1;
  }
  ST=st[n]*2+1; MX=ST*5;
  for (i=0; i<n; i++) for (j=0; j<n; j++)
    if (s[j].length()>=s[i].length() && s[j].substr(0,s[i].length())==s[i]) {
      maketransfer(0,j,s[i].length(),0,s[i].length());
      if (i!=j) maketransfer(0,j,s[i].length(),1,s[i].length());
    }
  for (i=0; i<n; i++) for (j=1; j<s[i].length(); j++) {
    rst=s[i].substr(j);
    for (k=0; k<n; k++) if (s[k].length()>=rst.length()) {
      if (s[k].substr(0,rst.length())==rst) {
        maketransfer((st[i]+j)*2-2,k,rst.length(),1,rst.length());
        maketransfer((st[i]+j)*2-3,k,rst.length(),0,rst.length());
      }
    } else {
      if (rst.substr(0,s[k].length())==s[k]) {
        maketransfer((st[i]+j)*2-2,i,j+s[k].length(),0,s[k].length());
        maketransfer((st[i]+j)*2-3,i,j+s[k].length(),1,s[k].length());
      }
    }
  }
  for (i=0; i<MX; i++) {
    if (i-ST>=0) ++a[i][i-ST];
    c[i][i]=1;
  }
  for (ii=29; ii>=0; ii--) {
    for (i=0; i<MX; i++) for (j=0; j<MX; j++) for (f[i][j]=k=0; k<MX; k++) {
      f[i][j]+=c[i][k]*c[k][j];
      if (f[i][j]>=md) f[i][j]%=md;
    }
    if ((m>>ii)&1) {
      for (i=0; i<MX; i++) for (j=0; j<MX; j++) for (c[i][j]=k=0; k<MX; k++) {
        c[i][j]+=a[i][k]*f[k][j];
        if (c[i][j]>=md) c[i][j]%=md;
      }
    } else for (i=0; i<MX; i++) for (j=0; j<MX; j++) c[i][j]=f[i][j];
  }
  printf("%lld\n",c[0][0]);
  return 0;
}