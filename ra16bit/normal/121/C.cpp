#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n,m,N,x,i,s,b[22];
long long f[15],a[2222];
bool u[15];
set <long long> st;
void rec(int l, long long s) {
  if (l>0) { a[n++]=s; st.insert(s); }
  if (l<10) rec(l+1,s*10+4);
  if (l<10) rec(l+1,s*10+7);
}
void build(int l, int x) {
  if (l==0) return;
  for (int j=0; j<x; j++) if (!u[j]) {
    if (f[l-1]>=m) {
      u[j]=true;
      b[x-l+1]=j+1;
      build(l-1,x);
      break;
    } else m-=f[l-1];
  }
}
int main() {
  rec(0,0);
  sort(a,a+n); N=n;
  scanf("%d%d",&n,&m);
  for (f[0]=i=1; i<15; i++) f[i]=f[i-1]*i;
  if (n<15 && m>f[n]) { puts("-1"); return 0; }
  build(min(14,n),min(14,n));
  if (n<=14) {
    if (b[4]==4 || b[4]==7) s++;
    if (b[7]==7 || b[7]==4) s++;
  } else {
    x=n-14;
    for (i=0; i<N; i++) if (a[i]<=x) s++;
    for (i=1; i<=14; i++) if (st.count(x+i) && st.count(x+b[i])) s++;
  }
  printf("%d\n",s);
  return 0;
}