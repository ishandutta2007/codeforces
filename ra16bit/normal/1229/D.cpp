#include <bits/stdc++.h>
using namespace std;
int n,m,num,i,j,x,y,z,fi,fr,q[122],a[7],b[7],e[122][122],all[122],k[122],lst[122],o[100100],was[122];
long long nxt,r;
bool u[7],u2[7];
void rec2(int l, int c, int p) {
  if (l>m) {
    int cur=0;
    for (int i=1; i<=m; i++) cur=cur*10+a[b[i]];
    e[o[p]][o[c]]=o[cur];
    return;
  }
  for (int i=1; i<=m; i++) if (!u2[i]) {
    u2[i]=true;
    b[l]=i;
    rec2(l+1,c*10+i,p);
    u2[i]=false;
  }
}
void rec(int l, int c, bool first) {
  if (l>m) {
    if (first) {
      o[c]=k[num]=num;
      all[num++]=c;
    } else {
      rec2(1,0,c);
    }
    return;
  }
  for (int i=1; i<=m; i++) if (!u[i]) {
    u[i]=true;
    a[l]=i;
    rec(l+1,c*10+i,first);
    u[i]=false;
  }
}
bool cmp(int i, int j) {
  return lst[i]>lst[j];
}
int main() {
  scanf("%d%d",&n,&m);
  rec(1,0,true);
  rec(1,0,false);
  for (i=1; i<=n; i++) {
    for (z=j=0; j<m; j++) {
      scanf("%d",&x);
      z=z*10+x;
    }
    lst[o[z]]=i;
    sort(k,k+num,cmp);
    for (fr=j=0; j<num; j++) {
      x=k[j];
      if (lst[x]==0) break;
      if (was[x]!=i) {
        fi=fr; q[fr++]=x;
        for (was[x]=i; fi<fr; fi++) {
          for (z=0; z<=fi; z++) {
            y=e[q[z]][q[fi]];
            if (was[y]!=i) { was[y]=i; q[fr++]=y; }
            y=e[q[fi]][q[z]];
            if (was[y]!=i) { was[y]=i; q[fr++]=y; }
          }
        }
      }
      nxt=(j+1<num)?lst[k[j+1]]:0;
      r+=(lst[x]-nxt)*fr;
    }
  }
  printf("%I64d\n",r);
  return 0;
}