#include <bits/stdc++.h>
using namespace std;
const int MX=270270;
struct Node {
  int s;
  bool need;
} b[MX*2];
int t,n,q,i,l[MX],r[MX];
char s[MX],f[MX];
void init(int i, int L, int R) {
  b[i].need=false;
  if (L==R) {
    b[i].s=f[R]-'0';
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  b[i].s=b[i*2].s+b[i*2+1].s;
}
void setv(int i, int v) {
  b[i].s=v;
  b[i].need=true;
}
void push(int i, int L, int h, int R) {
  setv(i*2,int(b[i].s>0)*(h-L+1));
  setv(i*2+1,int(b[i].s>0)*(R-h));
  b[i].need=false;
}
int fsum(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return b[i].s;
  int h=(L+R)/2,cur=0;
  if (b[i].need) push(i,L,h,R);
  if (le<=h) cur+=fsum(i*2,L,h,le,min(ri,h));
  if (ri>h) cur+=fsum(i*2+1,h+1,R,max(le,h+1),ri);
  return cur;
}
void mdf(int i, int L, int R, int le, int ri, int v) {
  if (L==le && R==ri) {
    b[i].s=v*(R-L+1);
    b[i].need=true;
    return;
  }
  int h=(L+R)/2;
  if (b[i].need) push(i,L,h,R);
  if (le<=h) mdf(i*2,L,h,le,min(ri,h),v);
  if (ri>h) mdf(i*2+1,h+1,R,max(le,h+1),ri,v);
  b[i].s=b[i*2].s+b[i*2+1].s;
}
bool check(int i, int L, int R) {
  if (L==R) return (b[i].s==s[R]-'0');
  int h=(L+R)/2;
  if (b[i].need) push(i,L,h,R);
  if (!check(i*2,L,h)) return false;
  return check(i*2+1,h+1,R);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    scanf("%s",f);
    init(1,0,n-1);
    for (i=0; i<q; i++) scanf("%d%d",&l[i],&r[i]);
    for (i=q-1; i>=0; i--) {
      --l[i];
      --r[i];
      int len=r[i]-l[i]+1;
      int cur=fsum(1,0,n-1,l[i],r[i]);
      if (cur*2==len) break;
      mdf(1,0,n-1,l[i],r[i],int(cur*2>len));
    }
    if (i>=0) { puts("NO"); continue; }
    puts(check(1,0,n-1)?"YES":"NO");
  }
  return 0;
}