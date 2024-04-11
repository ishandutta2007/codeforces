#include <bits/stdc++.h>
using namespace std;
const int MX=1000100,MXL=MX*8;
const long long SD=(1LL<<20);
int n,q,i,j,k,x,y,z,cur,bn,cn,b[22],c[22],a[150150],u[MX],p[MX],rk[MX];
set<long long> s;
long long now;
bool ok0,ok1;
int fs(int i) {
  if (i!=p[i]) p[i]=fs(p[i]);
  return p[i];
}
void un(int i, int j) {
  if (i==j) return;
  if (rk[i]>=rk[j]) {
    p[j]=i;
    if (rk[i]==rk[j]) ++rk[i];
  } else p[i]=j;
}
int main() {
  for (i=2; i<MX; i++) if (!u[i]) {
    for (j=i; j<MX; j+=i) u[j]=i;
    p[i]=i;
  }
  scanf("%d%d",&n,&q);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    for (bn=0, cur=a[i]; cur>1; ) {
      b[bn]=u[cur];
      if (bn>0) un(fs(b[bn]),fs(b[bn-1]));
      while (cur%b[bn]==0) cur/=b[bn];
      ++bn;
    }
  }
  for (i=0; i<n; i++) {
    x=fs(u[a[i]]);
    for (cn=0, cur=a[i]+1; cur>1; ) {
      c[cn]=u[cur];
      y=fs(c[cn]);
      if (x<y) s.insert(x*SD+y); else if (x>y) s.insert(y*SD+x);
      for (j=0; j<cn; j++) {
        z=fs(c[j]);
        if (z<y) s.insert(z*SD+y); else if (z>y) s.insert(y*SD+z);
      }
      while (cur%c[cn]==0) cur/=c[cn];
      ++cn;
    }
  }
  while (q--) {
    scanf("%d%d",&x,&y);
    x=fs(u[a[x-1]]);
    y=fs(u[a[y-1]]);
    ok0=ok1=false;
    if (x==y) ok0=true; else {
      if (x>y) swap(x,y);
      if (s.count(x*SD+y)) ok1=true;
    }
    puts(ok0?"0":(ok1?"1":"2"));
  }
  return 0;
}