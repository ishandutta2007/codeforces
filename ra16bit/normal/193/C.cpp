#include <cstdio>
#include <algorithm>
using namespace std;
const int x[6]={0,0,0,1,1,2};
const int y[6]={1,2,3,2,3,3};
struct Drob {
  int p,q;
  Drob norm() {
    if (q==0) q=1;
    int d=abs(__gcd(p,q));
    p/=d;
    q/=d;
    if (q<0) { p=-p; q=-q; }
    return *this;
  }
} a[8][8],b[8],res[8],d,two,len;
int i,j,k,p,pos,tot,best,v[8],w[8],ans[8];
char r[4][1000100];
Drob operator - (const Drob& a, const Drob& b) {
  Drob cur;
  cur.q=a.q*b.q;
  cur.p=a.p*b.q-b.p*a.q;
  return cur.norm();

}
Drob operator * (const Drob& a, const Drob& b) {
  Drob cur;
  cur.p=a.p*b.p;
  cur.q=a.q*b.q;
  return cur.norm();
}
Drob operator / (const Drob& a, const Drob& b) {
  Drob cur;
  cur.p=a.p*b.q;
  cur.q=a.q*b.p;
  return cur.norm();
}
int main() {
  for (i=0; i<6; i++) { scanf("%d",&b[i].p); b[i].q=1; }
  for (i=0; i<8; i++) {
    for (j=0; j<6; j++) {
      if (((i>>x[j])&1)!=((i>>y[j])&1)) a[j][i].p=1;
      a[j][i].q=1;
    }
    w[i]=-1;
  }
  for (i=0; i<6; i++) {
    for (j=0; j<8; j++) if (a[i][j].p!=0) break;
    v[i]=j; w[j]=i;
    for (k=i+1; k<6; k++) if (a[k][j].p!=0) {
      d=a[k][j]/a[i][j];
      for (p=0; p<8; p++) a[k][p]=a[k][p]-a[i][p]*d;
      b[k]=b[k]-b[i]*d;
    }
  }
  for (i=5; i>=0; i--) {
    j=v[i];
    for (k=i-1; k>=0; k--) if (a[k][j].p!=0) {
      d=a[k][j]/a[i][j];
      for (p=0; p<8; p++) a[k][p]=a[k][p]-a[i][p]*d;
      b[k]=b[k]-b[i]*d;
    }
  }
  for (pos=7; pos>=0; pos--) if (w[pos]<0) {
    best=-1;
    res[pos].q=1;
    for (res[pos].p=0; res[pos].p<=100000; res[pos].p++) {
      tot=res[pos].p;
      for (i=5; i>=0; i--) {
        j=v[i];
        res[j]=(b[i]-a[i][pos]*res[pos])/a[i][j];
        if ((res[j].p!=0 && res[j].q!=1) || res[j].p<0) break;
        tot+=res[j].p;
      }
      if (i<0 && (best==-1 || tot<best)) {
        best=tot;
        for (i=0; i<8; i++) ans[i]=res[i].p;
      }
    }
    break;
  }
  if (best>=0) {
    for (i=j=0; i<ans[1]; i++,j++) {
      r[0][j]='a'; r[1][j]='b';
      r[2][j]='b'; r[3][j]='b';
    }
    for (i=0; i<ans[2]; i++,j++) {
      r[0][j]='a'; r[1][j]='b';
      r[2][j]='a'; r[3][j]='a';
    }
    for (i=0; i<ans[3]; i++,j++) {
      r[0][j]='a'; r[1][j]='a';
      r[2][j]='b'; r[3][j]='b';
    }
    for (i=0; i<ans[4]; i++,j++) {
      r[0][j]='a'; r[1][j]='a';
      r[2][j]='b'; r[3][j]='a';
    }
    for (i=0; i<ans[5]; i++,j++) {
      r[0][j]='a'; r[1][j]='b';
      r[2][j]='a'; r[3][j]='b';
    }
    for (i=0; i<ans[6]; i++,j++) {
      r[0][j]='a'; r[1][j]='b';
      r[2][j]='b'; r[3][j]='a';
    }
    for (i=0; i<ans[7]; i++,j++) {
      r[0][j]='a'; r[1][j]='a';
      r[2][j]='a'; r[3][j]='b';
    }
    printf("%d\n",best);
    for (i=0; i<4; i++) puts(r[i]);
  } else puts("-1");
  return 0;
}