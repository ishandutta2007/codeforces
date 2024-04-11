#include <bits/stdc++.h>
using namespace std;
const int MX=22*22,md=31607;
int n,i,j,r,pwo,pwk[MX],a[25][25],b[25][25],c[25][25],st[25],Q[25];
int pw(int a, int b) {
  if (b==0) return 1;
  if (b&1) return (pw(a,b-1)*a)%md;
  int x=pw(a,b/2);
  return (x*x)%md;
}
void rec(int l, int p, int z) {
  if (l==n) {
    //for (int i=0; i<n; i++,puts("")) for (int j=0; j<n; j++) printf("%d",c[i][j]);
    for (int j=0; j<n; j++) p=(p*(Q[j]+md-st[j]))%md;
    //printf("=%d (%c)\n",p,(z?'-':'+'));
    if (z) r=(r+md-p)%md; else r=(r+p)%md;
    return;
  }
  rec(l+1,p,z);
  if (l==-2) {
    for (int i=0; i<n; i++) if (++c[i][i]==1) {
      st[i]=(st[i]*b[i][i])%md;
      Q[i]=(Q[i]*pwo)%md;
      p=(p*a[i][i])%md;
    }
    rec(l+1,p,z^1);
    for (int i=0; i<n; i++) if (--c[i][i]==0) {
      st[i]=(st[i]*a[i][i])%md;
      Q[i]=(Q[i]*pwk[1])%md;
    }
  } else if (l==-1) {
    for (int i=0; i<n; i++) if (++c[n-1-i][i]==1) {
      st[i]=(st[i]*b[n-i-1][i])%md;
      Q[i]=(Q[i]*pwo)%md;
      p=(p*a[n-1-i][i])%md;
    }
    rec(l+1,p,z^1);
    for (int i=0; i<n; i++) if (--c[n-1-i][i]==0) {
      st[i]=(st[i]*a[n-i-1][i])%md;
      Q[i]=(Q[i]*pwk[1])%md;
    }
  } else {
    for (int i=0; i<n; i++) if (++c[l][i]==1) {
      st[i]=(st[i]*b[l][i])%md;
      Q[i]=(Q[i]*pwo)%md;
      p=(p*a[l][i])%md;
    }
    rec(l+1,p,z^1);
    for (int i=0; i<n; i++) if (--c[l][i]==0) {
      st[i]=(st[i]*a[l][i])%md;
      Q[i]=(Q[i]*pwk[1])%md;
    }
  }
}
int main() {
  for (pwk[0]=i=1; i<MX; i++) pwk[i]=(pwk[i-1]*10000)%md;
  pwo=pw(pwk[1],md-2);
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  for (j=0; j<n; j++) { st[j]=1; Q[j]=pwk[n]; }
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    st[j]=(st[j]*a[i][j])%md;
    b[i][j]=pw(a[i][j],md-2);
  }
  r=pwk[n*n];
  rec(-2,1,1);
  printf("%d\n",(r*pw(pwk[n*n],md-2))%md);
  return 0;
}