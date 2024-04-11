#include <bits/stdc++.h>
using namespace std;
const int MX=264200;
struct Node {
  int mx1,mx2,cnt,add;
  long long sum;
  bool push;
} b[2*MX];
int n,q,i,t,x,y;
pair<int,int> a[MX];
void init(int i, int L, int R) {
  b[i].cnt=R-L+1;
  if (L==R) return;
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
void push(int i, int L, int R) {
  b[i].push=false;
  b[i*2].push=true;
  b[i*2+1].push=true;
  b[i*2].mx1=min(b[i*2].mx1,b[i].mx1);
  b[i*2+1].mx1=min(b[i*2+1].mx1,b[i].mx1);
  b[i*2].mx2=min(b[i*2].mx2,b[i].mx1);
  b[i*2+1].mx2=min(b[i*2+1].mx2,b[i].mx1);
}
void recalc(int i) {
  b[i].mx1=max(b[i*2].mx1,b[i*2+1].mx1);
  b[i].cnt=int(b[i].mx1==b[i*2].mx1)*b[i*2].cnt+int(b[i].mx1==b[i*2+1].mx1)*b[i*2+1].cnt;
  b[i].mx2=min(b[i*2].mx2,b[i*2+1].mx2);
  if (b[i*2].mx2!=b[i].mx1 && b[i*2].mx2>b[i].mx2) b[i].mx2=b[i*2].mx2;
  if (b[i*2].mx1!=b[i].mx1 && b[i*2].mx1>b[i].mx2) b[i].mx2=b[i*2].mx1;
  if (b[i*2+1].mx2!=b[i].mx1 && b[i*2+1].mx2>b[i].mx2) b[i].mx2=b[i*2+1].mx2;
  if (b[i*2+1].mx1!=b[i].mx1 && b[i*2+1].mx1>b[i].mx2) b[i].mx2=b[i*2+1].mx1;
  /*if (i==8) printf("recalc %d : %d %d %d [%d %d %d and %d %d %d]\n",i,b[i].cnt,b[i].mx1,b[i].mx2
  ,b[i*2].cnt,b[i*2].mx1,b[i*2].mx2
  ,b[i*2+1].cnt,b[i*2+1].mx1,b[i*2+1].mx2
  );*/
}
void add(int i, int L, int R, int le, int ri, int v) {
  if (L==le && R==ri) {
    b[i].add+=v;
    b[i].sum+=v*(R-L+1LL);
    return;
  }
  int h=(L+R)/2;
  if (le<=h) add(i*2,L,h,le,min(ri,h),v);
  if (ri>h) add(i*2+1,h+1,R,max(le,h+1),ri,v);
  b[i].sum=b[i].add*(R-L+1LL)+b[i*2].sum+b[i*2+1].sum;
}
void upd(int i, int L, int R, int ri) { // [1..ri] min= ri
  if (R<=ri) {
    if (b[i].mx1<=ri) return;
    assert((b[i].cnt==R-L+1)==(b[i].mx1==b[i].mx2));
    if (b[i].cnt==R-L+1 || b[i].mx2<ri) {
      add(1,1,n,ri+1,b[i].mx1,-b[i].cnt);
      b[i].mx1=ri;
      b[i].mx2=min(b[i].mx2,ri);
      b[i].push=true;
      return;
    }
  }
  if (b[i].push) push(i,L,R);
  int h=(L+R)/2;
  upd(i*2,L,h,ri);
  if (ri>h) upd(i*2+1,h+1,R,ri);
  recalc(i);
}
void put(int i, int L, int R, int x, int y) { // [x] := y
  if (L==R) {
    if (x<n && x<b[i].mx1) add(1,1,n,x+1,b[i].mx1,-1);
    b[i].mx1=b[i].mx2=y;
    b[i].cnt=1;
    if (x<n && x<y) add(1,1,n,x+1,y,1);
    return;
  }
  if (b[i].push) push(i,L,R);
  int h=(L+R)/2;
  if (x<=h) put(i*2,L,h,x,y); else put(i*2+1,h+1,R,x,y);
  recalc(i);
}
long long findsum(int i, int L, int R, int le, int ri, int add) {
  if (L==le && R==ri) return b[i].sum+add*(R-L+1LL);
  int h=(L+R)/2;
  long long res=0;
  if (le<=h) res+=findsum(i*2,L,h,le,min(ri,h),add+b[i].add);
  if (ri>h) res+=findsum(i*2+1,h+1,R,max(h+1,le),ri,add+b[i].add);
  return res;
}
int main() {
  scanf("%d%d",&n,&q);
  init(1,1,n);
  while (q--) {
    scanf("%d%d%d",&t,&x,&y);
    if (t==1) {
      put(1,1,n,x,y);
      if (x>1) upd(1,1,n,x-1);
    } else printf("%lld\n",y-x+1LL+findsum(1,1,n,x,y,0));
  }
  return 0;
}