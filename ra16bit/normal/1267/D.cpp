#include <bits/stdc++.h>
using namespace std;
int n,i,j,x,fi,fr,q[11],p[11],a[444],b[444],ra[100100],rb[100100],r;
bool u[444],w[11],ok;
bool check(int y, int z) {
  int x=(y|z);
  if (w[x]) return true;
  for (i=0; i<n; i++) if (!u[i] && a[i]==x) break;
  if (i>=n) return true;
  if (!w[y] || !w[z]) return false;
  ra[r]=p[y]; rb[r++]=i;
  ra[r]=p[z]; rb[r++]=i;
  u[i]=true;
  p[x]=i;
  for (++i; i<n; i++) if (!u[i] && a[i]==x) {
    u[i]=true;
    ra[r]=p[x];
    rb[r++]=i;
  }
  return true;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<3; j++) {
    scanf("%d",&x);
    a[i]|=(x<<j);
  }
  for (i=0; i<n; i++) for (j=0; j<3; j++) {
    scanf("%d",&x);
    b[i]|=(x<<j);
  }
  q[fi=0]=7; p[7]=0;
  u[0]=w[7]=true;
  for (fr=1; fi<fr; fi++) {
    for (i=0; i<n; i++) if (a[i]==q[fi] && !u[i]) {
      ra[r]=p[q[fi]];
      rb[r++]=i;
      u[i]=true;
      x=(a[i]&b[i]);
      if (!w[x]) {
        w[x]=true;
        p[x]=i;
        q[fr++]=x;
      }
    }
  }
  ok=(check(1,2) && check(1,4) && check(2,4));
  for (i=0; i<n; i++) if (!u[i]) ok=false;
  if (ok && r<265) {
    puts("Possible");
    for (i=0; i<n; i++) printf("%d%c",int(w[a[i]&b[i]] && p[a[i]&b[i]]==i),(i==n-1)?'\n':' ');
    printf("%d\n",r);
    for (i=0; i<r; i++) printf("%d %d\n",ra[i]+1,rb[i]+1);
  } else puts("Impossible");
  return 0;
}