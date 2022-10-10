#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=525525;
int i,j,x,n,a[MX],b[MX*2],mx[18][MX];
long long r;
void init(int i, int L, int R) {
  if (L==R) {
    b[i]=R;
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  if (a[b[i*2]]>a[b[i*2+1]]) b[i]=b[i*2]; else b[i]=b[i*2+1];
}
int fndmax(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return b[i];
  int mid=(L+R)/2,res=0;
  if (le<=mid) {
    res=fndmax(i*2,L,mid,le,min(ri,mid));
    if (ri>mid) {
      int cur=fndmax(i*2+1,mid+1,R,mid+1,ri);
      if (a[cur]>=a[res]) res=cur;
    }
  } else res=fndmax(i*2+1,mid+1,R,le,ri);
  return res;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[n-1-i]);
  for (i=0; i<n; i++) {
    a[i+n]=min(2*n,n+i+a[i]);
    a[i]=min(2*n,i+a[i]);
  }
  a[2*n]=2*n;
  init(1,0,2*n);
  for (i=0; i<2*n; i++) {
    mx[0][i]=fndmax(1,0,2*n,i+1,min(a[i],2*n));
  }
  for (j=1; j<18; j++) for (i=0; i<2*n; i++) mx[j][i]=(mx[j-1][i]==2*n)?2*n:mx[j-1][mx[j-1][i]];
  for (r=i=0; i<n; i++, r++) {
    if (a[i]>=i+n-1) continue;
    x=i;
    for (j=17; j>=0; j--) if (a[mx[j][x]]<i+n-1) {
      r+=(1<<j);
      x=mx[j][x];
    }
    r++;
  }
  printf("%I64d\n",r);
  return 0;
}