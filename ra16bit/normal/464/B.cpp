#include <cstdio>
#include <algorithm>
using namespace std;
int cnt,a[8][3],c[8][3],p[8][3],b[8],d[8];
bool u[8],q;
long long sqr(long long x) { return x*x; }
long long dist(int i, int j) {
  return sqr(c[i][0]-c[j][0])+sqr(c[i][1]-c[j][1])+sqr(c[i][2]-c[j][2]);
}
void pre(int l) {
  if (l==3) {
    for (int i=0; i<3; i++) p[cnt][i]=b[i];
    cnt++;
    return;
  }
  for (int i=0; i<3; i++) if (!u[i]) {
    u[i]=true;
    b[l]=i;
    pre(l+1);
    u[i]=false;
  }
}
void fill(int l, int k, int e) {
  for (int i=0; i<3; i++) c[l][i]=c[k][i]+c[e][i]-c[0][i];
}
bool find(int l) {
  for (int i=0; i<3; i++) d[i]=c[l][i];
  sort(d,d+3);
  for (int i=0; i<8; i++) if (!u[i]) {
    int j=0;
    for (j=0; j<3; j++) if (d[j]!=a[i][j]) break;
    if (j>=3) {
      b[l]=i;
      u[i]=true;
      return true;
    }
  }
  return false;
}
void rec(int l) {
  if (l==4) {
    long long d=dist(0,1);
    if (d==0) return;
    if (dist(0,2)!=d) return;
    if (dist(0,3)!=d) return;
    for (int i=1; i<4; i++) for (int j=i+1; j<4; j++) if (dist(i,j)!=2*d) return;
    fill(4,1,2); if (!find(4)) return;
    fill(5,1,3); if (!find(5)) { u[b[4]]=false; return; }
    fill(6,2,3); if (!find(6)) { u[b[4]]=u[b[5]]=false; return; }
    fill(7,4,3); if (!find(7)) { u[b[4]]=u[b[5]]=u[b[6]]=false; return; }
    q=true;
    puts("YES");
    for (int i=0; i<8; i++) for (int j=0; j<3; j++) a[b[i]][j]=c[i][j];
    for (int i=0; i<8; i++) for (int j=0; j<3; j++) printf("%d%c",a[i][j],j==2?'\n':' ');
    return;
  }
  for (int i=0; i<8; i++) if (!u[i]) {
    u[i]=true;
    b[l]=i;
    for (int j=0; j<6; j++) {
      for (int k=0; k<3; k++) c[l][k]=a[i][p[j][k]];
      rec(l+1);
      if (q) return;
    }
    u[i]=false;
    if (i==0 && l==0) break;
  }
}
int main() {
  for (int i=0; i<8; i++) {
    for (int j=0; j<3; j++) scanf("%d",&a[i][j]);
    sort(a[i],a[i]+3);
  }
  pre(0);
  rec(0);
  if (!q) puts("NO");
  return 0;
}