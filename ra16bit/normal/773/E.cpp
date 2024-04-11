#include <bits/stdc++.h>
using namespace std;
const int MID=500002;
struct Node {
  int mn,add;
} a[2100100];
int n,i,beg,cur,x[MID],cnt[MID+5];
void init(int i, int L, int R) {
  a[i].mn=L-MID;
  if (L==R) return;
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
void mdf(int i, int L, int R, int ri, int v) {
  if (R==ri) {
    a[i].add+=v;
    a[i].mn+=v;
    return;
  }
  int h=(L+R)/2;
  mdf(i*2,L,h,min(ri,h),v);
  if (ri>h) mdf(i*2+1,h+1,R,ri,v);
  a[i].mn=min(a[i*2].mn,a[i*2+1].mn)+a[i].add;
}
int ans(int i, int L, int R) {
  if (L==beg) return a[i].mn;
  int h=(L+R)/2;
  if (beg>h) return ans(i*2+1,h+1,R)+a[i].add;
  return min(a[i*2+1].mn,ans(i*2,L,h))+a[i].add;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&x[i]);
  init(1,0,2*MID);
  beg=MID;
  for (i=0; i<n; i++) {
    cur=x[i]+MID;
    if (cur<beg) {
      ++cnt[cur];
      if (--cnt[beg]<0) --beg;
    }
    mdf(1,0,2*MID,cur-1,1);
    printf("%d\n",ans(1,0,2*MID));
  }
  return 0;
}