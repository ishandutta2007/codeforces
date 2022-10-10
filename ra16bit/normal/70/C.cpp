#include <cstdio>
#include <map>
#include <utility>
using namespace std;
int ii,i,j,k,e,d,n,m,w,r1,r2,a[200200],o[200200],b[200200],c[200200],p[7];
map <pair <int, int>, int> mm;
pair <int, int> cur;
long long res,r,rz,cw;
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
int main() {
  res=200000; res*=res; rz=res;
  for (i=1; i<=100000; i++) {
    ii=i;
    for (j=0; j<6; j++) { p[j]=ii%10; ii/=10; }
    for (j=0; j<6; j++) ii=ii*10+p[j];
    while (ii%10==0) ii/=10;
    d=gcd(i,ii);
    cur=make_pair(i/d,ii/d);
    a[i]=mm[cur];
    if (a[i]==0) mm[cur]=a[i]=++e;
    cur=make_pair(ii/d,i/d);
    o[i]=mm[cur];
    if (o[i]==0) mm[cur]=o[i]=++e;
  }
  scanf("%d%d%d",&n,&m,&w); r=m;
  for (j=1; j<=m; j++) b[a[j]]++;
  for (i=1; i<=n; i++) {
    c[o[i]]++;
    cw+=b[o[i]];
    for (; r>1; r--) {
      if (cw-c[a[r]]<w) break;
      cw-=c[a[r]]; b[a[r]]--;
    }
    if (cw>=w && r*i<res) { res=r*i; r1=i; r2=r; }
  }
  if (res<rz) printf("%d %d\n",r1,r2); else puts("-1");
  return 0;
}