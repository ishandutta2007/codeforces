#include <bits/stdc++.h>
using namespace std;
const int MX=300300,MID=MX*2;
int n,i,x,y,it,a[MX],mx[MX],mn[MX],cnt[MID*2],u[MID*2];
long long res;
void upd(int x, int v) {
  if (u[MID+x]!=it) {
    u[MID+x]=it;
    cnt[MID+x]=v;
  } else cnt[MID+x]+=v;
}
void solve(int le, int ri) {
  if (le==ri) {
    ++res;
    return;
  }
  int h=(le+ri)/2;
  solve(le,h);
  solve(h+1,ri);
  for (int i=0; i<2; i++) mn[h+i]=mx[h+i]=a[h+i];
  for (int i=h-1; i>=le; i--) {
    mn[i]=min(a[i],mn[i+1]);
    mx[i]=max(a[i],mx[i+1]);
  }
  for (int i=h+2; i<=ri; i++) {
    mn[i]=min(a[i],mn[i-1]);
    mx[i]=max(a[i],mx[i-1]);
  }
  ++it;
  int kx=h+1,ky=h+1;
  for (int i=h; i>=le; i--) { // mn in left part
    int len=mx[i]-mn[i];
    int j=i+len;
    if (j>h && j<=ri && mx[j]<mx[i] && mn[j]>mn[i]) res++; // mx in left part
    for (; kx<=ri && mn[kx]>mn[i]; kx++) upd(mx[kx]-kx,1);
    for (; ky<kx && mx[ky]<mx[i]; ky++) upd(mx[ky]-ky,-1);
    if (u[MID+mn[i]-i]==it) res+=cnt[MID+mn[i]-i]; // mx in right part: mx[k]-k==mn[i]-i
  }
  ++it;
  kx=ky=h;
  for (int i=h+1; i<=ri; i++) { // mn in right part
    int len=mx[i]-mn[i];
    int j=i-len;
    if (j<=h && j>=le && mx[j]<mx[i] && mn[j]>mn[i]) res++; // mx in right part
    for (; kx>=le && mn[kx]>mn[i]; kx--) upd(mx[kx]+kx,1);
    for (; ky>kx && mx[ky]<mx[i]; ky--) upd(mx[ky]+ky,-1);
    if (u[MID+mn[i]+i]==it) res+=cnt[MID+mn[i]+i]; // mx in left part: mx[k]+k==mn[i]+i
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    a[x]=y;
  }
  solve(1,n);
  printf("%I64d\n",res);
  return 0;
}